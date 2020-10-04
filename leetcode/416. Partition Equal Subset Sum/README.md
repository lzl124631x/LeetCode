# [416. Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum/)

<p>Given a <b>non-empty</b> array containing <b>only positive integers</b>, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.</p>

<p><b>Note:</b></p>

<ol>
	<li>Each of the array element will not exceed 100.</li>
	<li>The array size will not exceed 200.</li>
</ol>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre>Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre>Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)

## Solution 1. 0-1 Knapsack

```cpp
// OJ: https://leetcode.com/problems/partition-equal-subset-sum/
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(NS)
class Solution {
public:
    bool canPartition(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 2) return false;
        int N = A.size();
        sum /= 2;
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= N; ++i) dp[i][0] = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp[i + 1][j] = dp[i][j] || (j >= A[i] && dp[i][j - A[i]]);
            }
        }
        return dp[N][sum];
    }
};
```

## Solution 2. 0-1 Knapsack

Since `dp[i + 1][j]` is only dependent on values in the previous row, we can reduce the size of the `dp` array from `N * S` to `1 * S`.

```cpp
// OJ: https://leetcode.com/problems/partition-equal-subset-sum/
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(S)
class Solution {
public:
    bool canPartition(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 2) return false;
        int N = A.size();
        sum /= 2;
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for (int i = 0; i < N; ++i) {
            for (int j = sum; j >= A[i]; --j) {
                dp[j] = dp[j] || dp[j - A[i]];
            }
        }
        return dp[sum];
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/partition-equal-subset-sum
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(S) where S the sum of nums.
class Solution {
private:
  bool subsetSum(vector<int> &nums, int S) {
    vector<int> dp(S + 1);
    dp[0] = 1;
    for (int n : nums)
      for (int i = S; i >= n; --i) dp[i] += dp[i - n];
    return dp[S];
  }
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum % 2 == 0 && subsetSum(nums, sum / 2);
  }
};
```

## Solution 3. DP

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
  bool canPartition(vector<int>& nums) {
    const int MAX_NUM = 100;
    const int MAX_ARRAY_SIZE = 200;
    bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (auto n : nums) bits |= bits << n;
    return !(sum & 1) && bits[sum >> 1];
  }
};
```