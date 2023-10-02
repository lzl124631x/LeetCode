# [1293. Shortest Path in a Grid with Obstacles Elimination (Hard)](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

<p>You are given an <code>m x n</code> integer matrix <code>grid</code> where each cell is either <code>0</code> (empty) or <code>1</code> (obstacle). You can move up, down, left, or right from and to an empty cell in <strong>one step</strong>.</p>

<p>Return <em>the minimum number of <strong>steps</strong> to walk from the upper left corner </em><code>(0, 0)</code><em> to the lower right corner </em><code>(m - 1, n - 1)</code><em> given that you can eliminate <strong>at most</strong> </em><code>k</code><em> obstacles</em>. If it is not possible to find such walk return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/30/short1-grid.jpg" style="width: 244px; height: 405px;">
<pre><strong>Input:</strong> grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -&gt; (0,1) -&gt; (0,2) -&gt; (1,2) -&gt; (2,2) -&gt; <strong>(3,2)</strong> -&gt; (4,2).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/30/short2-grid.jpg" style="width: 244px; height: 245px;">
<pre><strong>Input:</strong> grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> We need to eliminate at least two obstacles to find such a walk.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 40</code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
	<li><code>grid[i][j]</code> is either <code>0</code> <strong>or</strong> <code>1</code>.</li>
	<li><code>grid[0][0] == grid[m - 1][n - 1] == 0</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Amazon](https://leetcode.com/company/amazon), [Pinterest](https://leetcode.com/company/pinterest)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Shortest Path to Get Food (Medium)](https://leetcode.com/problems/shortest-path-to-get-food/)

## Note

1. If `K >= M + N - 3`, we can reach the destination with number of steps equaling the Manhattan Distance between `(0,0)` and `(M-1,N-1)`, i.e. `M+N-2`.  
Since `K` is at most `M * N`, this check can help reduce `K` significantly from `O(MN)` to `O(M+N)`.
2. Since we are looking for the shortest distance, BFS should be the first option. We can BFS the grid **layer by layer**, and the steps we've taken to reach `(M-1,N-1)` the first time is the answer.
3. Normally we use `seen[x][y] = true` to denote that we've visited cell `(x,y)`. But in this case, **we want to visit the same cell again (with more steps) if we have more bombs available**, because using having more bombs available for later might help us get to `(M-1,N-1)` quicker.

Example:

Assume we can reach `(1, 4)` in two ways: 
1. 5 steps with 0 bombs available
2. 9 steps with 1 bombs available

We definitely need to try the 2nd case with more bombs available, even though it took more steps.

```
? ? ? ? ?
? ? ? ? 0
? ? ? 1 1
? ? ? 1 0
```

## Solution 1. BFS (seen[x][y][bomb] as boolean)

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

Or we can BFS continuously.

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

## Solution 2. BFS (seen[x][y] as the maximum bombs available when reaching `(x,y)`)

Similar to Solution 1, instead of using `seen[x][y][b]` to denote whether we visited cell `(x, y)` with `b` bombs, we use `seen[x][y]` as the maximum bombs available when reaching cell `(x, y)`.

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
        int M = G.size(), N = G[0].size(), step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        if (k >= M + N - 3) return M + N - 2;
        vector<vector<int>> seen(M, vector<int>(N, -1)); // maximum bomb available when visiting (x, y)
        seen[0][0] = k;
        queue<tuple<int, int, int>> q{{{0,0,k}}}; // x, y, bomb
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, bomb] = q.front();
                q.pop();
                if (x == M - 1 && y == N - 1) return step;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N) continue;
                    int newBomb = bomb - G[a][b];
                    if (newBomb <= seen[a][b]) continue; // We only visit a cell if we have more bombs available than before.
                    seen[a][b] = newBomb;
                    q.emplace(a, b, newBomb);
                }
            }
            ++step;
        }
        return -1;
    }
};
```

Or we can BFS continuously

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
        vector<vector<int>> seen(M, vector<int>(N, -1)); // maximum bomb available when visiting (x, y)
        seen[0][0] = k;
        queue<tuple<int, int, int, int>> q{{{0,0,k,0}}}; // x, y, bomb, step
        while (q.size()) {
            auto [x, y, bomb, step] = q.front();
            q.pop();
            if (x == M - 1 && y == N - 1) return step;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N) continue;
                int newBomb = bomb - G[a][b];
                if (newBomb <= seen[a][b]) continue; // We only visit a cell if we have more bombs available than before.
                seen[a][b] = newBomb;
                q.emplace(a, b, newBomb, step + 1);
            }
        }
        return -1;
    }
};
```

## Solution 3. DFS

We should use BFS instead of DFS when searching for the shortest path. Just for completeness, a DFS solution is listed here.

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MN * min(K, M + N))
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

## Solution 4. BFS + DP

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MN * min(K, M + N))
class Solution {
public:
    int shortestPath(vector<vector<int>>& G, int k) {
        int M = G.size(), N = G[0].size(), dp[40][40][80] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        k = min(k, M + N - 2);
        memset(dp, 0x3f, sizeof(dp));
        queue<array<int, 3>> q{{{0, 0, 0}}}; // x, y, bomb
        dp[0][0][0] = 0; // dp[x][y][b] is the minimum distance to get to (x, y) with `b` bombs
        while (q.size()) {
            auto [x, y, bomb] = q.front();
            q.pop();
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || b < 0 || a >= M || b >= N) continue;
                int newBomb = bomb + G[a][b], dist = dp[x][y][bomb] + 1;
                if (bomb <= k && dp[a][b][newBomb] > dist) {
                    dp[a][b][newBomb] = dist;
                    q.push({a, b, newBomb});
                }
            }
        }
        int ans = *min_element(begin(dp[M - 1][N - 1]), end(dp[M - 1][N - 1]));
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};
```