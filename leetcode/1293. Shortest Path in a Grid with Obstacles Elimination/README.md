# [1293. Shortest Path in a Grid with Obstacles Elimination (Hard)](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

<p>Given a <code>m * n</code> grid, where each cell is either <code>0</code> (empty)&nbsp;or <code>1</code> (obstacle).&nbsp;In one step, you can move up, down, left or right from and to an empty cell.</p>

<p>Return the minimum number of steps to walk from the upper left corner&nbsp;<code>(0, 0)</code>&nbsp;to the lower right corner&nbsp;<code>(m-1, n-1)</code> given that you can eliminate&nbsp;<strong>at most</strong> <code>k</code> obstacles. If it is not possible to find such&nbsp;walk return -1.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 
grid = 
[[0,0,0],
&nbsp;[1,1,0],
 [0,0,0],
&nbsp;[0,1,1],
 [0,0,0]], 
k = 1
<strong>Output:</strong> 6
<strong>Explanation: 
</strong>The shortest path without eliminating any obstacle is 10.&nbsp;
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is <code>(0,0) -&gt; (0,1) -&gt; (0,2) -&gt; (1,2) -&gt; (2,2) -&gt; <strong>(3,2)</strong> -&gt; (4,2)</code>.
</pre>

<p>&nbsp;</p>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
grid = 
[[0,1,1],
&nbsp;[1,1,1],
&nbsp;[1,0,0]], 
k = 1
<strong>Output:</strong> -1
<strong>Explanation: 
</strong>We need to eliminate at least two obstacles to find such a walk.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>grid.length&nbsp;== m</code></li>
	<li><code>grid[0].length&nbsp;== n</code></li>
	<li><code>1 &lt;= m, n &lt;= 40</code></li>
	<li><code>1 &lt;= k &lt;= m*n</code></li>
	<li><code>grid[i][j] == 0 <strong>or</strong> 1</code></li>
	<li><code>grid[0][0] == grid[m-1][n-1] == 0</code></li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Note

1. If `K >= M + N - 3`, we can reach the destination with number of steps equaling the Manhattan Distance between `(0,0)` and `(M-1,N-1)`, i.e. `M+N-2`.  
Since `K` is at most `M * N`, this check can help reduce `K` significantly from `O(MN)` to `O(M+N)`.
2. Since we are looking for the shortest distance, BFS should be the first option.

## Solution 1. BFS (Layer by Layer)

If `k = 0`, we will just use a plain BFS to get the shortest path.

Now consider we have some bombs, for the same cell `(x, y)`, using some bomb might help us get to this cell faster.

Assume `f(x, y, b)` is the shortest path to get to cell `(x, y)` with `b` bombs used (`b <= k`).

The answer would be `min( f(M-1, N-1, b) | 0 <= b <= k )`.

Since we are using BFS layer by layer, the first visit to cell `(M-1, N-1)` will tell us the length of the shortest path.

Example: Consider the following grid and `k = 1`.

For simplicity, assume we want to go from `(0, 0)` to `(0, N-1)`. If we don't use bomb, the shortest distance is `6`. If we use one bomb, the shortest distance is `2`.

```
0 1 0
0 1 0
0 0 0
```

We start with state `f(0, 0, 0) = 0`.

Moving downwards results in `f(1, 0, 0) = 1`.

Moving rightwards results in `f(0, 1, 1) = 1`. Note that we used one bomb in order to step on cell `(0, 1)`.

Moving rightwards from `f(0, 1, 1) = 1` will results in `f(0, 2, 1) = 2`. So `2` is the shortest distance.

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MN * min(K, M + N))
class Solution {
public:
    int shortestPath(vector<vector<int>>& G, int k) {
        int M = G.size(), N = G[0].size(), step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        if (k >= M + N - 3) return M + N - 2;
        bool seen[40][40][80] = {};
        queue<tuple<int, int, int>> q; // x, y, bomb
        q.emplace(0, 0, 0);
        seen[0][0][0] = true;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, bomb] = q.front();
                q.pop();
                if (x == M - 1 && y == N - 1) return step;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N) continue;
                    int nextBomb = bomb + G[a][b];
                    if (nextBomb > k || seen[a][b][nextBomb]) continue;
                    q.emplace(a, b, nextBomb);
                    seen[a][b][nextBomb] = true;
                }
            }
            ++step;
        }
        return -1;
    }
};
```

## Solution 2. BFS (Continuously)

Almost the same as Solution 1, here we are not doing BFS layer by layer, but doing it continuously. We need each state be a tuple of `(x, y, bomb, step)`.

Since `(x, y, bomb)` uniquely corresponds to a single smallest `step`, the `seen` array is still 3 dimensional.

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MNK)
// Ref: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/451787/Python-O(m*n*k)-BFS-Solution-with-Explanation
class Solution {
public:
    int shortestPath(vector<vector<int>>& G, int k) {
        int M = G.size(), N = G[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        if (k >= M + N - 3) return M + N - 2;
        bool seen[40][40][80] = {};
        queue<tuple<int, int, int, int>> q; // x, y, bomb, step
        q.emplace(0, 0, 0, 0);
        seen[0][0][0] = true;
        while (q.size()) {
            auto [x, y, bomb, step] = q.front();
            q.pop();
            if (x == M - 1 && y == N - 1) return step;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N) continue;
                int nextBomb = bomb + G[a][b];
                if (nextBomb > k || seen[a][b][nextBomb]) continue;
                q.emplace(a, b, nextBomb, step + 1);
                seen[a][b][nextBomb] = true;
            }
        }
        return -1;
    }
};
```

## Solution 3. BFS

Similar to Solution 1, instead of using `seen[x][y][b]` to denote whether we visited cell `(x, y)` with `b` bombs, we use `seen[x][y]` as the least bombs needed to get to cell `(x, y)`.

Consider the following case:

```
0 0 0
1 1 0
0 0 0
0 1 1
0 0 0
```

We can get to `(2, 1)` with 1 bomb in 3 steps:

* `(0,0) -> (0,1) -> (1,1) -> (2,1)`. We set `seen[2][0] = 1`, and push `(x,y,bomb) = (2,1,1)` into the queue.
* `(0,0) -> (1,0) -> (2,0) -> (2,1)`. This path takes the same number of steps and bombs, so we don't need to push `(x,y,bomb) = (2,1,1)` into the queue again.

We can get to `(2, 1)` with 2 bombs in 3 steps:

* `(0,0) -> (1,0) -> (1,1) -> (2,1)`. This path takes the same number of steps but more bombs, so it won't be better than what we've seen before. We don't push `(x,y,bomb) = (2,1,2)` into the queue.

We can get to `(2,1)` with 0 bomb in 5 steps:

* `(0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (2,1)`. This path takes more steps but less bombs. Even though it takes more steps as of now, with the saved bombs, we might be able to take some shortcut later to save steps. So we should push `(x,y,bomb) = (2,1,0)` into the queue.

Now we can see that, we can get to the same cell `(x, y)` through different paths with different bombs. 

* If we reach `(x, y)` with LESS bombs than before, we push `(x, y, bomb)` into the queue
* If we reach `(x, y)` with the SAME or MORE bombs than before, we don't push `(x, y, bomb)` into the queue.

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MN)
class Solution {
public:
    int shortestPath(vector<vector<int>>& G, int k) {
        int M = G.size(), N = G[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        if (k >= M + N - 3) return M + N - 2;
        int seen[40][40] = {}, step = 0; // seen[x][y] is the number of bombs we used to get to cell (x, y)
        memset(seen, 0x3f, sizeof(seen));
        seen[0][0] = 0;
        queue<tuple<int, int, int>> q; // x, y, bomb
        q.emplace(0, 0, 0);
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, bomb] = q.front();
                q.pop();
                if (x == M - 1 && y == N - 1) return step;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N) continue;
                    int nextBomb = bomb + G[a][b];
                    if (nextBomb >= seen[a][b] || nextBomb > k) continue; // If we reached (a,b) with more bombs that before, this state is no better than before so we shouldn't push it into queue.
                    q.emplace(a, b, nextBomb);
                    seen[a][b] = nextBomb;
                }
            }
            ++step;
        }
        return -1;
    }
};
```

## Solution 4. DFS

We should use BFS instead of DFS when searching for the shortest path. Just for completeness, a DFS solution is listed here.

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MNK)
class Solution {
    int M, N, dp[40][40][80] = {}, dirs[4][2] = {{0,1}, {0,-1},{1,0},{-1,0}}, ans = INT_MAX;
    void dfs(vector<vector<int>> &G, int x, int y, int k, int step) {
        dp[x][y][k] = step;
        if (x == M - 1 && y == N - 1) ans = min(ans, step);
        for (auto [dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            if (a < 0 || a >= M || b < 0 || b >= N) continue;
            if (k - G[x][y] >= 0 && dp[a][b][k - G[x][y]] > step + 1) dfs(G, a, b, k - G[x][y], step + 1);
        }
    }
public:
    int shortestPath(vector<vector<int>>& G, int k) {
        M = G.size(), N = G[0].size();
        if (k >= M + N - 3) return M + N - 2;
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < k; ++i) dp[0][0][k] = 0;
        dfs(G, 0, 0, k, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
```