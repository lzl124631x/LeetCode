# [1254. Number of Closed Islands (Medium)](https://leetcode.com/problems/number-of-closed-islands/)

<p>Given a 2D&nbsp;<code>grid</code> consists of <code>0s</code> (land)&nbsp;and <code>1s</code> (water).&nbsp; An <em>island</em> is a maximal 4-directionally connected group of <code><font face="monospace">0</font>s</code> and a <em>closed island</em>&nbsp;is an island <strong>totally</strong>&nbsp;(all left, top, right, bottom) surrounded by <code>1s.</code></p>

<p>Return the number of <em>closed islands</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png" style="width: 240px; height: 120px;"></p>

<pre><strong>Input:</strong> grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Islands in gray are closed because they are completely surrounded by water (group of 1s).</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/10/31/sample_4_1610.png" style="width: 160px; height: 80px;"></p>

<pre><strong>Input:</strong> grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,1,1,1,1,1],
&nbsp;              [1,0,0,0,0,0,1],
&nbsp;              [1,0,1,1,1,0,1],
&nbsp;              [1,0,1,0,1,0,1],
&nbsp;              [1,0,1,1,1,0,1],
&nbsp;              [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[0].length &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;=1</code></li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/number-of-closed-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
    int dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, M, N;
    bool dfs(vector<vector<int>> &G, int x, int y, int id) {
        G[x][y] = id;
        bool ans = true;
        for (auto &[dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            bool oob = a < 0 || b < 0 || a >= M || b >= N;
            ans = ans && !oob;
            if (oob || G[a][b] != 0) continue;
            ans = dfs(G, a, b, id) && ans;
        }
        return ans;
    }
public:
    int closedIsland(vector<vector<int>>& G) {
        int id = 2, ans = 0;
        M = G.size(), N = G[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] != 0) continue;
                if (dfs(G, i, j, id++)) ++ans;
            }
        }
        return ans;
    }
};
```