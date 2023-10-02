# [698. Partition to K Equal Sum Subsets (Medium)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)

<p>Given an array of integers <code>nums</code> and a positive integer <code>k</code>, find whether it's possible to divide this array into <code>k</code> non-empty subsets whose sums are all equal.</p>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> nums = [4, 3, 2, 3, 5, 2, 1], k = 4
<b>Output:</b> True
<b>Explanation:</b> It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ul>
	<li><code>1 &lt;= k &lt;= len(nums) &lt;= 16</code>.</li>
	<li><code>0 &lt; nums[i] &lt; 10000</code>.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Partition Equal Subset Sum (Medium)](https://leetcode.com/problems/partition-equal-subset-sum/)

## Note

This problem is very similar to [473. Matchsticks to Square (Medium)](https://leetcode.com/problems/matchsticks-to-square/).

## Solution 1. Bitmask DP on Subsets

```cpp
// OJ: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^Nk)
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % k) return false;
        int N = A.size();
        sum /= k;
        vector<int> dp(1 << N, -1); // -1 unvisited, 0 can't k-partition, 1 can k-partition
        dp[(1 << N) - 1] = 1; // If we can use all elements, it's a valid k-partition
        sort(begin(A), end(A), greater<>()); // Try the rocks earlier than sands
        function<bool(int, int)> dfs = [&](int mask, int target) {
            if (dp[mask] != -1) return dp[mask];
            dp[mask] = 0;
            if (target == 0) target = sum;
            for (int i = 0; i < N && !dp[mask]; ++i) {
                if ((mask >> i & 1) || A[i] > target) continue; // If `A[i]` is used in `mask`, or `A[i] > target`, skip this `A[i]`
                dp[mask] = dfs(mask | (1 << i), target - A[i]);
            }
            return dp[mask];
        };
        return dfs(0, sum);
    }
};
```

## Solution 2. Backtrack to Fill Buckets 

```cpp
// OJ: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Author: github.com/lzl124631x
// Time: O(K^N)
// Space: O(N * SUM(A) / K)
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int sum = accumulate(begin(A), end(A), 0), N = A.size();
        if (sum % k) return false;
        sum /= k;
        sort(begin(A), end(A), greater<>()); // try rocks before sands
        vector<int> s(k);
        function<bool(int)> dfs = [&](int i) {
            if (i == N) return true;
            for (int j = 0; j < k; ++j) {
                if (s[j] + A[i] > sum) continue;
                s[j] += A[i];
                if (dfs(i + 1)) return true;
                s[j] -= A[i];
                if (s[j] == 0) break; // don't try empty buckets multiple times
            }
            return false;
        };
        return dfs(0);
    }
};
```