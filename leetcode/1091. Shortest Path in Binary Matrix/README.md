# [1091. Shortest Path in Binary Matrix (Medium)](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

<p>Given an <code>n x n</code> binary matrix <code>grid</code>, return <em>the length of the shortest <strong>clear path</strong> in the matrix</em>. If there is no clear path, return <code>-1</code>.</p>

<p>A <strong>clear path</strong> in a binary matrix is a path from the <strong>top-left</strong> cell (i.e., <code>(0, 0)</code>) to the <strong>bottom-right</strong> cell (i.e., <code>(n - 1, n - 1)</code>) such that:</p>

<ul>
	<li>All the visited cells of the path are <code>0</code>.</li>
	<li>All the adjacent cells of the path are <strong>8-directionally</strong> connected (i.e., they are different and they share an edge or a corner).</li>
</ul>

<p>The <strong>length of a clear path</strong> is the number of visited cells of this path.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/example1_1.png" style="width: 500px; height: 234px;">
<pre><strong>Input:</strong> grid = [[0,1],[1,0]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/example2_1.png" style="height: 216px; width: 500px;">
<pre><strong>Input:</strong> grid = [[0,0,0],[1,1,0],[1,1,0]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0,0],[1,1,0],[1,1,0]]
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>grid[i][j] is 0 or 1</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

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

Or

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N) for elements in the queue
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& A) {
        if (A[0][0]) return -1;
        int N = A.size(), ans = 1;
        queue<pair<int, int>> q{{{0,0}}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == N - 1 && y == N - 1) return ans;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        int a = x + dx, b = y + dy;
                        if (a < 0 || b < 0 || a >= N || b >= N || A[a][b]) continue;
                        A[a][b] = 1;
                        q.emplace(a, b);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
```