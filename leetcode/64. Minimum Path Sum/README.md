# [64. Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)

<p>Given a <code>m x n</code> <code>grid</code> filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.</p>

<p><strong>Note:</strong> You can only move either down or right at any point in time.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,2,3],[4,5,6]]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)
* [Maximum Number of Points with Cost (Medium)](https://leetcode.com/problems/maximum-number-of-points-with-cost/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-path-sum/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int sum = min(i - 1 >= 0 ? A[i - 1][j] : INT_MAX, j - 1 >= 0 ? A[i][j - 1] : INT_MAX);
                A[i][j] += sum == INT_MAX ? 0 : sum;
            }
        }
        return A[M - 1][N - 1];
    }
};
```