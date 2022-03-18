# [1368. Minimum Cost to Make at Least One Valid Path in a Grid (Hard)](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

<p>Given an <code>m x n</code> grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of <code>grid[i][j]</code> can be:</p>

<ul>
	<li><code>1</code> which means go to the cell to the right. (i.e go from <code>grid[i][j]</code> to <code>grid[i][j + 1]</code>)</li>
	<li><code>2</code> which means go to the cell to the left. (i.e go from <code>grid[i][j]</code> to <code>grid[i][j - 1]</code>)</li>
	<li><code>3</code> which means go to the lower cell. (i.e go from <code>grid[i][j]</code> to <code>grid[i + 1][j]</code>)</li>
	<li><code>4</code> which means go to the upper cell. (i.e go from <code>grid[i][j]</code> to <code>grid[i - 1][j]</code>)</li>
</ul>

<p>Notice that there could be some signs on the cells of the grid that point outside the grid.</p>

<p>You will initially start at the upper left cell <code>(0, 0)</code>. A valid path in the grid is a path that starts from the upper left cell <code>(0, 0)</code> and ends at the bottom-right cell <code>(m - 1, n - 1)</code> following the signs on the grid. The valid path does not have to be the shortest.</p>

<p>You can modify the sign on a cell with <code>cost = 1</code>. You can modify the sign on a cell <strong>one time only</strong>.</p>

<p>Return <em>the minimum cost to make the grid have at least one valid path</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/13/grid1.png" style="width: 400px; height: 390px;">
<pre><strong>Input:</strong> grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --&gt; (0, 1) --&gt; (0, 2) --&gt; (0, 3) change the arrow to down with cost = 1 --&gt; (1, 3) --&gt; (1, 2) --&gt; (1, 1) --&gt; (1, 0) change the arrow to down with cost = 1 --&gt; (2, 0) --&gt; (2, 1) --&gt; (2, 2) --&gt; (2, 3) change the arrow to down with cost = 1 --&gt; (3, 3)
The total cost = 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/13/grid2.png" style="width: 350px; height: 341px;">
<pre><strong>Input:</strong> grid = [[1,1,3],[3,2,2],[1,1,4]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> You can follow the path from (0, 0) to (2, 2).
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/13/grid3.png" style="width: 200px; height: 192px;">
<pre><strong>Input:</strong> grid = [[1,2],[4,3]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 4</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Matrix](https://leetcode.com/tag/matrix/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [Minimum Weighted Subgraph With the Required Paths (Hard)](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/)

## Solution 1. BFS + DP

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minCost(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size(), dp[100][100] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        queue<pair<int, int>> q{{{0, 0}}};
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + dirs[i][0], b = y + dirs[i][1];
                if (a < 0 || b < 0 || a >= M || b >= N) continue;
                int cost = dp[x][y] + (G[x][y] - 1 != i);
                if (dp[a][b] > cost) {
                    dp[a][b] = cost;
                    q.emplace(a, b);
                }
            }
        }
        return dp[M - 1][N - 1];
    }
};
```

## Solution 2. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// Author: github.com/lzl124631x
// Time: O(MNlogMN)
// Space: O(MN)
class Solution {
public:
    int minCost(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size(), dist[100][100] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({ 0, 0, 0 });
        while (pq.size()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (d > dist[x][y]) continue;
            if (x == M - 1 && y == N - 1) return d;
            for (int i = 0; i < 4; ++i) {
                int a = x + dirs[i][0], b = y + dirs[i][1];
                if (a < 0 || a >= M || b < 0 || b >= N) continue;
                int cost = d + (G[x][y] - 1 != i);
                if (cost < dist[a][b]) {
                    dist[a][b] = cost;
                    pq.push({ cost, a, b });
                }
            }
        }
        return 0;
    }
};
```