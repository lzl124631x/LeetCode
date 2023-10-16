# [416. Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum)

<p>Given an integer array <code>nums</code>, return <code>true</code> <em>if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,5,11,5]
<strong>Output:</strong> true
<strong>Explanation:</strong> The array can be partitioned as [1, 5, 5] and [11].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,5]
<strong>Output:</strong> false
<strong>Explanation:</strong> The array cannot be partitioned into equal sum subsets.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Yahoo](https://leetcode.com/company/yahoo), [TikTok](https://leetcode.com/company/tiktok), [Expedia](https://leetcode.com/company/expedia), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Uber](https://leetcode.com/company/uber), [LinkedIn](https://leetcode.com/company/linkedin), [Bloomberg](https://leetcode.com/company/bloomberg), [ByteDance](https://leetcode.com/company/bytedance), [Infosys](https://leetcode.com/company/infosys), [Hive](https://leetcode.com/company/hive), [eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets)
* [Minimize the Difference Between Target and Chosen Elements (Medium)](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements)
* [Maximum Number of Ways to Partition an Array (Hard)](https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array)
* [Partition Array Into Two Arrays to Minimize Sum Difference (Hard)](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference)
* [Find Subarrays With Equal Sum (Easy)](https://leetcode.com/problems/find-subarrays-with-equal-sum)
* [Number of Great Partitions (Hard)](https://leetcode.com/problems/number-of-great-partitions)
* [Split With Minimum Sum (Easy)](https://leetcode.com/problems/split-with-minimum-sum)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/partition-equal-subset-sum/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    bool canPartition(vector<int>& A) { 
        int total = accumulate(begin(A), end(A), 0);
        if (total % 2) return false;
        unordered_set<int> s, next;
        for (int n : A) {
            next = s;
            for (int m : s) next.insert(m + n);
            next.insert(n);
            if (next.count(total / 2)) return true;
            swap(s, next);
        }
        return false;
    }
};
```

## Solution 2. 0-1 Knapsack

Let `dp[i+1][j]` be whether we can sum to `j` using numbers in `A[0]` to `A[i]`.

We have two options for `dp[i+1][j]`:
* We skip `A[i]`. Then `dp[i+1][j] = dp[i][j]`.
* We pick `A[i]`. Then `dp[i+1][j] = dp[i][j-A[i]]`.

```
dp[i+1][j] = dp[i][j] || (j >= A[i] && dp[i][j - A[i]])

dp[i][0] = true where 0 <= i <= N
```

If any `dp[i + 1][sum / 2]` is `true`, we return `true`. Otherwise, return `false`.

```cpp
// OJ: https://leetcode.com/problems/partition-equal-subset-sum/
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(NS)
class Solution {
public:
    bool canPartition(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0), N = A.size();
        if (sum % 2) return false;
        sum /= 2;
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1));
        for (int i = 0; i <= N; ++i) dp[i][0] = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp[i + 1][j] = dp[i][j] || (j >= A[i] && dp[i][j - A[i]]);
            }
            if (dp[i + 1][sum]) return true;
        }
        return false;
    }
};
```

## Solution 3. 0-1 Knapsack with Space Optimization

Since `dp[i + 1][j]` only depends on values in the previous row, we can reduce the size of the `dp` array from `N * S` to `1 * S`.

```cpp
// OJ: https://leetcode.com/problems/partition-equal-subset-sum/
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(S)
class Solution {
public:
    bool canPartition(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0), N = A.size();
        if (sum % 2) return false;
        sum /= 2;
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for (int i = 0; i < N; ++i) {
            for (int j = sum; j >= A[i]; --j) {
                dp[j] = dp[j] || dp[j - A[i]];
            }
            if (dp[sum]) return true;
        }
        return false;
    }
};
```

## Solution 4. DP (Bitmask Subset Sum)

Create a bitmask `bits` of size `MAX_NUM * MAX_ARRAY_SIZE / 2 + 1`. If we can sum to `i`, then `bits[i] = 1`; otherwise `bits[i] = 0`.

When we use `A[i]` to update the result, we add `A[i]` to all the numbers that we can form previously, i.e. `bits << n`.

We merge the result using `bits |= bits << n`.

`bits[sum / 2]` is the result.

```cpp
// OJ: https://leetcode.com/problems/partition-equal-subset-sum
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(MAX_NUM * MAX_ARRAY_SIZE)
// Ref: https://discuss.leetcode.com/topic/62334/simple-c-4-line-solution-using-a-bitset
class Solution {
public:
    bool canPartition(vector<int>& A) {
        const int MAX_NUM = 100, MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 2) return false;
        for (int n : A) bits |= bits << n;
        return bits[sum / 2];
    }
};
```

## NOTE

Related to [494. Target Sum (Medium)](https://leetcode.com/problems/target-sum/)