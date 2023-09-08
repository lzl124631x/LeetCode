# [2304. Minimum Path Cost in a Grid (Medium)](https://leetcode.com/problems/minimum-path-cost-in-a-grid)

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> integer matrix <code>grid</code> consisting of <strong>distinct</strong> integers from <code>0</code> to <code>m * n - 1</code>. You can move in this matrix from a cell to any other cell in the <strong>next</strong> row. That is, if you are in cell <code>(x, y)</code> such that <code>x &lt; m - 1</code>, you can move to any of the cells <code>(x + 1, 0)</code>, <code>(x + 1, 1)</code>, ..., <code>(x + 1, n - 1)</code>. <strong>Note</strong> that it is not possible to move from cells in the last row.</p>
<p>Each possible move has a cost given by a <strong>0-indexed</strong> 2D array <code>moveCost</code> of size <code>(m * n) x n</code>, where <code>moveCost[i][j]</code> is the cost of moving from a cell with value <code>i</code> to a cell in column <code>j</code> of the next row. The cost of moving from cells in the last row of <code>grid</code> can be ignored.</p>
<p>The cost of a path in <code>grid</code> is the <strong>sum</strong> of all values of cells visited plus the <strong>sum</strong> of costs of all the moves made. Return <em>the <strong>minimum</strong> cost of a path that starts from any cell in the <strong>first</strong> row and ends at any cell in the <strong>last</strong> row.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/28/griddrawio-2.png" style="width: 301px; height: 281px;">
<pre><strong>Input:</strong> grid = [[5,3],[4,0],[2,1]], moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
<strong>Output:</strong> 17
<strong>Explanation: </strong>The path with the minimum possible cost is the path 5 -&gt; 0 -&gt; 1.
- The sum of the values of cells visited is 5 + 0 + 1 = 6.
- The cost of moving from 5 to 0 is 3.
- The cost of moving from 0 to 1 is 8.
So the total cost of the path is 6 + 3 + 8 = 17.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> grid = [[5,1,2],[4,0,3]], moveCost = [[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The path with the minimum possible cost is the path 2 -&gt; 3.
- The sum of the values of cells visited is 2 + 3 = 5.
- The cost of moving from 2 to 3 is 1.
So the total cost of this path is 5 + 1 = 6.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid</code> consists of distinct integers from <code>0</code> to <code>m * n - 1</code>.</li>
	<li><code>moveCost.length == m * n</code></li>
	<li><code>moveCost[i].length == n</code></li>
	<li><code>1 &lt;= moveCost[i][j] &lt;= 100</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Paint House (Medium)](https://leetcode.com/problems/paint-house/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-path-cost-in-a-grid
// Author: github.com/lzl124631x
// Time: O(MN^2)
// Space: O(MN)
class Solution {
public:
    int minPathCost(vector<vector<int>>& A, vector<vector<int>>& C) {
        int M = A.size(), N = A[0].size(), ans = INT_MAX;
        vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
        for (int j = 0; j < N; ++j) dp[M - 1][j] = A[M - 1][j];
        for (int i = M - 2; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k] + A[i][j] + C[A[i][j]][k]);
                }
                if (i == 0) ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/minimum-path-cost-in-a-grid
// Author: github.com/lzl124631x
// Time: O(MN^2)
// Space: O(N) if we are not allowed to compute values in-place
class Solution {
public:
    int minPathCost(vector<vector<int>>& A, vector<vector<int>>& C) {
        int M = A.size(), N = A[0].size(), ans = INT_MAX;
        for (int i = M - 2; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                int mn = INT_MAX;
                for (int k = 0; k < N; ++k) {
                    mn = min(mn, A[i + 1][k] + C[A[i][j]][k]);
                }
                A[i][j] += mn;
                if (i == 0) ans = min(ans, A[i][j]);
            }
        }
        return ans;
    }
};
```