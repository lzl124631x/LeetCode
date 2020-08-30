# [1568. Minimum Number of Days to Disconnect Island (Medium)](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)

<p>Given a 2D&nbsp;<code>grid</code> consisting&nbsp;of <code>1</code>s (land)&nbsp;and <code>0</code>s (water).&nbsp; An <em>island</em> is a maximal 4-directionally (horizontal or vertical) connected group of <code>1</code>s.</p>

<p>The grid is said to be <strong>connected</strong> if we have <strong>exactly one&nbsp;island</strong>, otherwise is said <strong>disconnected</strong>.</p>

<p>In one day, we are allowed to change <strong>any </strong>single land cell <code>(1)</code> into a water cell <code>(0)</code>.</p>

<p>Return <em>the minimum number of days</em> to disconnect the grid.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/13/1926_island.png" style="width: 498px; height: 139px;"></strong></p>

<pre><strong>Input:</strong> grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1]]
<strong>Output:</strong> 2
<strong>Explanation: </strong>Grid of full water is also disconnected ([[1,1]] -&gt; [[0,0]]), 0 islands.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0,1,0]]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,0,1,1],
&nbsp;              [1,1,1,1,1],
&nbsp;              [1,1,0,1,1],
&nbsp;              [1,1,0,1,1]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,0,1,1],
&nbsp;              [1,1,1,1,1],
&nbsp;              [1,1,0,1,1],
&nbsp;              [1,1,1,1,1]]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code>&nbsp;is <code>0</code> or <code>1</code>.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

You need at most two days to separate out a `1` at the corner with all other `1`s. So the answer is one of `0`, `1`, `2`.

If the graph is already disconnected, return `0`.

For each `1`, see if removing it can disconnect the graph. If yes, then return `1`.

Otherwise return `2`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(MN)
class Solution {
    int M, N, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>> &G, int i, int j,vector<vector<int>> &seen) {
        seen[i][j] = true;
        for (auto &[dx, dy] : dirs) {
            int x = dx + i, y = dy + j;
            if (x < 0 || x >= M || y < 0 || y >= N || G[x][y] != 1 || seen[x][y]) continue;
            dfs(G, x, y, seen);
        }
    }
    bool disconnected(vector<vector<int>> &G) {
        vector<vector<int>> seen(M, vector<int>(N, false));
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] != 1 || seen[i][j]) continue;
                if (++cnt > 1) return true;
                dfs(G, i, j, seen);
            }
        }
        return cnt == 0;
    }
public:
    int minDays(vector<vector<int>>& G) {
        M = G.size(), N = G[0].size();
        if (disconnected(G)) return 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] != 1) continue;
                G[i][j] = 0;
                if (disconnected(G)) return 1;
                G[i][j] = 1;
            }
        }
        return 2;
    }
};
```