# [1034. Coloring A Border (Medium)](https://leetcode.com/problems/coloring-a-border/)

<p>Given a 2-dimensional&nbsp;<code>grid</code> of integers, each value in the grid represents the color of the grid square at that location.</p>

<p>Two squares belong to the same <em>connected component</em> if and only if they have the same color and are next to each other in any of the 4 directions.</p>

<p>The&nbsp;<em>border</em> of a connected component is&nbsp;all the squares in the connected component that are&nbsp;either 4-directionally adjacent to&nbsp;a square not in the component, or on the boundary of the grid (the first or last row or column).</p>

<p>Given a square at location&nbsp;<code>(r0, c0)</code>&nbsp;in the grid and a <code>color</code>, color the&nbsp;border of the connected component of that square with the given <code>color</code>, and return the final <code>grid</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>grid = <span id="example-input-1-1">[[1,1],[1,2]]</span>, r0 = <span id="example-input-1-2">0</span>, c0 = <span id="example-input-1-3">0</span>, color = <span id="example-input-1-4">3</span>
<strong>Output: </strong><span id="example-output-1">[[3, 3], [3, 2]]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>grid = <span id="example-input-2-1">[[1,2,2],[2,3,2]]</span>, r0 = <span id="example-input-2-2">0</span>, c0 = <span id="example-input-2-3">1</span>, color = <span id="example-input-2-4">3</span>
<strong>Output: </strong><span id="example-output-2">[[1, 3, 3], [2, 3, 3]]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>grid = <span id="example-input-3-1">[[1,1,1],[1,1,1],[1,1,1]]</span>, r0 = <span id="example-input-3-2">1</span>, c0 = <span id="example-input-3-3">1</span>, color = <span id="example-input-3-4">2</span>
<strong>Output: </strong><span id="example-output-3">[[2, 2, 2], [2, 1, 2], [2, 2, 2]]</span></pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length &lt;= 50</code></li>
	<li><code>1 &lt;= grid[0].length &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 1000</code></li>
	<li><code>0 &lt;= r0 &lt; grid.length</code></li>
	<li><code>0 &lt;= c0 &lt; grid[0].length</code></li>
	<li><code>1 &lt;= color &lt;= 1000</code></li>
</ol>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/coloring-a-border/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(vector<vector<int>> &G, int x, int y, int color) {
        if (x < 0 || x >= G.size() || y < 0 || y >= G[0].size() || G[x][y] != color) return;
        bool border = false;
        for (auto &dir : dirs) {
            int a = x + dir[0], b = y + dir[1];
            if (a < 0 || a >= G.size() || b < 0 || b >= G[0].size() || (G[a][b] > 0 && G[a][b] != color)) {
                border = true;
                break;
            }
        }
        G[x][y] = -color - (border ? 1 : 0);
        for (auto &dir : dirs) dfs(G, x + dir[0], y + dir[1], color);
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& G, int r0, int c0, int color) {
        int c = G[r0][c0];
        dfs(G, r0, c0, c);
        for (int i = 0; i < G.size(); ++i) {
            for (int j = 0; j < G[0].size(); ++j) {
                if (G[i][j] < 0) G[i][j] = G[i][j] == -c ? c : color;
            }
        }
        return G;
    }
};
```