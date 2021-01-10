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

## Solution 1. DP on Subsets

```cpp
// OJ: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(2^Nk)
class Solution {
    vector<int> dp;
    bool dfs(vector<int> &A, int used, int todo, int target) {
        if (dp[used] != -1) return dp[used];
        dp[used] = 0;
        int rest = (todo - 1) % target + 1;
        for (int i = 0; i < A.size() && !dp[used]; ++i) {
            dp[used] = ((used >> i) & 1) == 0 && A[i] <= rest && dfs(A, used | (1 << i), todo - A[i], target);
        }
        return dp[used];
    }
public:
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % k || *max_element(begin(A), end(A)) > sum / k) return false;
        dp.assign(1 << A.size(), -1);
        dp[(1 << A.size()) - 1] = 1;
        return dfs(A, 0, sum, sum / k);
    }
};
```

## Solution 2. DFS to Fill Buckets

```cpp
// OJ: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Author: github.com/lzl124631x
// Time: O(K^N)
// Space: O(N * SUM(A) / K)
class Solution {
    vector<int> v;
    int target;
    bool dfs(vector<int> &A, int i) {
        if (i == A.size()) return true;
        unordered_set<int> seen;
        for (int j = 0; j < v.size(); ++j) {
            if (seen.count(v[j]) || v[j] + A[i] > target) continue;
            seen.insert(v[j]);
            v[j] += A[i];
            if (dfs(A, i + 1)) return true;
            v[j] -= A[i];
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % k) return false;
        target = sum / k;
        sort(begin(A), end(A), greater<>());
        v.assign(k, 0);
        return dfs(A, 0);
    }
};
```