# [2290. Minimum Obstacle Removal to Reach Corner (Hard)](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner)

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>grid</code> of size <code>m x n</code>. Each cell has one of two values:</p>

<ul>
	<li><code>0</code> represents an <strong>empty</strong> cell,</li>
	<li><code>1</code> represents an <strong>obstacle</strong> that may be removed.</li>
</ul>

<p>You can move up, down, left, or right from and to an empty cell.</p>

<p>Return <em>the <strong>minimum</strong> number of <strong>obstacles</strong> to <strong>remove</strong> so you can move from the upper left corner </em><code>(0, 0)</code><em> to the lower right corner </em><code>(m - 1, n - 1)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/06/example1drawio-1.png" style="width: 605px; height: 246px;">
<pre><strong>Input:</strong> grid = [[0,1,1],[1,1,0],[1,1,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/06/example1drawio.png" style="width: 405px; height: 246px;">
<pre><strong>Input:</strong> grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> <strong>or</strong> <code>1</code>.</li>
	<li><code>grid[0][0] == grid[m - 1][n - 1] == 0</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Matrix](https://leetcode.com/tag/matrix/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [Shortest Path in a Grid with Obstacles Elimination (Hard)](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

## Solution 1. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
        typedef array<int, 3> Node; // bomb, x, y
        priority_queue<Node, vector<Node>, greater<>> pq; // a min heap that the top element has the min bomb usage
        pq.push({ 0, 0, 0 });
        dist[0][0] = 0;
        while (pq.size()) {
            auto [bomb, x, y] = pq.top();
            pq.pop();
            if (bomb > dist[x][y]) continue;
            if (x == M - 1 && y == N - 1) return bomb;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N) continue;
                int newBomb = bomb + A[a][b];
                if (newBomb < dist[a][b]) {
                    dist[a][b] = newBomb;
                    pq.push({newBomb, a, b});
                }
            }
        }
        return -1;
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner
// Author: github.com/lzl124631x
// Time: O(MN * (M + N))
// Space: O(MN)
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
        typedef array<int, 3> Node;
        queue<Node> q;
        q.push({ 0, 0, 0 });
        dist[0][0] = 0;
        while (q.size()) {
            auto [x, y, bomb] = q.front();
            q.pop();
            if (bomb > dist[x][y]) continue;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N) continue;
                int newBomb = bomb + A[a][b];
                if (newBomb < dist[a][b]) {
                    dist[a][b] = newBomb;
                    q.push({a, b, newBomb});
                }
            }
        }
        return dist[M - 1][N - 1];
    }
};
```