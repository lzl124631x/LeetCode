# [505. The Maze II (Medium)](https://leetcode.com/problems/the-maze-ii)

<p>There is a ball in a <code>maze</code> with empty spaces (represented as <code>0</code>) and walls (represented as <code>1</code>). The ball can go through the empty spaces by rolling <strong>up, down, left or right</strong>, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.</p>
<p>Given the <code>m x n</code> <code>maze</code>, the ball's <code>start</code> position and the <code>destination</code>, where <code>start = [start<sub>row</sub>, start<sub>col</sub>]</code> and <code>destination = [destination<sub>row</sub>, destination<sub>col</sub>]</code>, return <em>the shortest <strong>distance</strong> for the ball to stop at the destination</em>. If the ball cannot stop at <code>destination</code>, return <code>-1</code>.</p>
<p>The <strong>distance</strong> is the number of <strong>empty spaces</strong> traveled by the ball from the start position (excluded) to the destination (included).</p>
<p>You may assume that <strong>the borders of the maze are all walls</strong> (see examples).</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
<strong>Output:</strong> 12
<strong>Explanation:</strong> One possible way is : left -&gt; down -&gt; left -&gt; down -&gt; right -&gt; down -&gt; right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/31/maze1-2-grid.jpg" style="width: 573px; height: 573px;">
<pre><strong>Input:</strong> maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>m == maze.length</code></li>
	<li><code>n == maze[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>start.length == 2</code></li>
	<li><code>destination.length == 2</code></li>
	<li><code>0 &lt;= start<sub>row</sub>, destination<sub>row</sub> &lt; m</code></li>
	<li><code>0 &lt;= start<sub>col</sub>, destination<sub>col</sub> &lt; n</code></li>
	<li>Both the ball and the destination exist in an empty space, and they will not be in the same position initially.</li>
	<li>The maze contains <strong>at least 2 empty spaces</strong>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [ByteDance](https://leetcode.com/company/bytedance), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [The Maze (Medium)](https://leetcode.com/problems/the-maze/)
* [The Maze III (Hard)](https://leetcode.com/problems/the-maze-iii/)

## Solution 1. BFS

We BFS the matrix step by step. Each state is `(x, y, direction)` and we visit them at most once.

The time complexity is `O(4MN) = O(MN)` because each state `(x, y, direction)` is visited at most once.

```cpp
// OJ: https://leetcode.com/problems/the-maze-ii/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int shortestDistance(vector<vector<int>>& A, vector<int>& S, vector<int>& E) {
        int M = A.size(), N = A[0].size(), step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<vector<bool>>> seen(M, vector<vector<bool>>(N, vector<bool>(4))); // (x, y, direction)
        queue<array<int, 3>> q;
        for (int i = 0; i < 4; ++i) {
            seen[S[0]][S[1]][i] = true;
            q.push({S[0], S[1], i});
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, dir] = q.front();
                q.pop();
                auto &[dx, dy] = dirs[dir];
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny]) { // The ball hits a wall. We can probe 4 directions
                    if (x == E[0] && y == E[1]) return step; // we can only check (x, y) if we are by a wall
                    for (int d = 0; d < 4; ++d) {
                        if (d == dir) continue;
                        auto &[dx, dy] = dirs[d];
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny] || seen[nx][ny][d]) continue;
                        seen[nx][ny][d] = true;
                        q.push({nx, ny, d});
                    }
                } else if (!seen[nx][ny][dir]) { // The ball doesn't hit a wall. We can only move in the same direction.
                    seen[nx][ny][dir] = true;
                    q.push({nx, ny, dir});
                }
            }
            ++step;
        }
        return -1;
    }
};
```

## Solution 2. Dijkstra (BFS + Heap)

Solution 1 has lots of intermediate states that are not valid because the ball is still rolling. Here we can only keep track of those valid states, and log their distance.

We need to use a min heap to prioritize the states with shorter distance. This is in fact a Dijkstra algorithm.

Note that we might visit the same cell multiple times, we should only push the state into the heap if the distance is shorter.

**Time complexity**:

In the worst case we visit each node (`O(MN)`), and for each node we probe 4 directions taking `O(max(M, N))` time, and pushing into / popping from the heap takes `O(log(MN))` time (assuming there are at most `O(MN)` elements in the heap). So, the overall time complexity is `O(MN * max(M, N) * log(MN))`.

But this is a loose upper bound because the more nodes visitable, the less steps we do during 4-directional probing.

This is more efficient than Solution 1 because we prioritize shorter distance and thus reach the end point earlier.

```cpp
// OJ: https://leetcode.com/problems/the-maze-ii/
// Author: github.com/lzl124631x
// Time: O(MN * max(M, N) * log(MN))
// Space: O(MN)
class Solution {
public:
    int shortestDistance(vector<vector<int>>& A, vector<int>& start, vector<int>& dest) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
        dist[start[0]][start[1]] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq; // min heap of (distance, x, y)
        pq.push({0, start[0], start[1]});
        while (pq.size()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            if (cost > dist[x][y]) continue; // this state is no longer optimial, skip
            if (x == dest[0] && y == dest[1]) return cost;
            for (auto &[dx, dy] : dirs) { // probe 4 directions
                int a = x, b = y, step = 0;
                while (a >= 0 && a < M && b >= 0 && b < N && A[a][b] == 0) a += dx, b += dy, ++step;
                a -= dx, b -= dy, --step; // once hit wall, step back
                if (dist[a][b] > cost + step) {
                    dist[a][b] = cost + step;
                    pq.push({ dist[a][b], a, b });
                }
            }
        }
        return -1;
    }
};
```