# [2556. Disconnect Path in a Binary Matrix by at Most One Flip (Medium)](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip)

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> <strong>binary</strong> matrix <code>grid</code>. You can move from a cell <code>(row, col)</code> to any of the cells <code>(row + 1, col)</code> or <code>(row, col + 1)</code> that has the value <code>1</code>.&nbsp;The matrix is <strong>disconnected</strong> if there is no path from <code>(0, 0)</code> to <code>(m - 1, n - 1)</code>.</p>
<p>You can flip the value of <strong>at most one</strong> (possibly none) cell. You <strong>cannot flip</strong> the cells <code>(0, 0)</code> and <code>(m - 1, n - 1)</code>.</p>
<p>Return <code>true</code> <em>if it is possible to make the matrix disconnect or </em><code>false</code><em> otherwise</em>.</p>
<p><strong>Note</strong> that flipping a cell changes its value from <code>0</code> to <code>1</code> or from <code>1</code> to <code>0</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/07/yetgrid2drawio.png" style="width: 441px; height: 151px;">
<pre><strong>Input:</strong> grid = [[1,1,1],[1,0,0],[1,1,1]]
<strong>Output:</strong> true
<strong>Explanation:</strong> We can change the cell shown in the diagram above. There is no path from (0, 0) to (2, 2) in the resulting grid.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/12/07/yetgrid3drawio.png">
<pre><strong>Input:</strong> grid = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is not possible to change at most one cell such that there is not path from (0, 0) to (2, 2).
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>grid[0][0] == grid[m - 1][n - 1] == 1</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Number of Submatrices That Sum to Target (Hard)](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)
* [Minimum Cost to Make at Least One Valid Path in a Grid (Hard)](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)
* [Minimum Number of Days to Disconnect Island (Hard)](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)
* [Minimum Weighted Subgraph With the Required Paths (Hard)](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(M + N)
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        function<bool(int, int)> dfs = [&](int x, int y) {
            if (x == M - 1 && y == N - 1) return true;
            if (x == M || y == N || A[x][y] == 0) return false;
            A[x][y] = 0;
            return dfs(x + 1, y) || dfs(x, y + 1);
        };
        if (!dfs(0, 0)) return true;
        A[0][0] = 1;
        return !dfs(0, 0);
    }
};
```