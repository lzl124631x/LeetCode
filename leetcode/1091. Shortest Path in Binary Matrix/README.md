# [1091. Shortest Path in Binary Matrix (Medium)](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

<p>In an N by N square grid, each cell is either empty (0) or blocked (1).</p>

<p>A&nbsp;<em>clear&nbsp;path from top-left to bottom-right</em>&nbsp;has length <code>k</code> if and only if it is composed of cells <code>C_1, C_2, ..., C_k</code>&nbsp;such that:</p>

<ul>
	<li>Adjacent cells <code>C_i</code> and <code>C_{i+1}</code> are connected 8-directionally (ie., they are different and&nbsp;share an edge or corner)</li>
	<li><code>C_1</code> is at location <code>(0, 0)</code> (ie. has value <code>grid[0][0]</code>)</li>
	<li><code>C_k</code>&nbsp;is at location <code>(N-1, N-1)</code> (ie. has value <code>grid[N-1][N-1]</code>)</li>
	<li>If <code>C_i</code> is located at&nbsp;<code>(r, c)</code>, then <code>grid[r][c]</code> is empty (ie.&nbsp;<code>grid[r][c] ==&nbsp;0</code>).</li>
</ul>

<p>Return the length of the shortest such clear path from top-left to bottom-right.&nbsp; If such a path does not exist, return -1.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[0,1],[1,0]]
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example1_1.png" style="width: 151px; height: 152px;">
</span>
<strong>Output: </strong>2
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example1_2.png" style="width: 151px; height: 152px;">
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[0,0,0],[1,1,0],[1,1,0]]
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example2_1.png" style="width: 151px; height: 152px;">
</span>
<strong>Output:</strong> 4
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example2_2.png" style="width: 151px; height: 152px;">
</pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length == grid[0].length &lt;= 100</code></li>
	<li><code>grid[r][c]</code> is <code>0</code> or <code>1</code></li>
</ol>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& G) {
        if (G[0][0] == 1) return -1;
        int N = G.size();
        vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        dist[0][0] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= N || b < 0 || b >= N || G[a][b] == 1 || dist[a][b] != INT_MAX) continue;
                    dist[a][b] = dist[x][y] + 1;
                    q.emplace(a, b);
                }
            }
        }
        return dist[N - 1][N - 1] == INT_MAX ? -1 : dist[N - 1][N - 1];
    }
};
```