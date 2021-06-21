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

## Solution 1. BFS + DP

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MNK)
class Solution {
public:
    int shortestPath(vector<vector<int>>& G, int K) {
        int M = G.size(), N = G[0].size(), dp[40][40][80], seen[40][40][80] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        memset(dp, 0x3f, sizeof(dp));
        if (K >= M + N - 3) return M + N - 2; // This line is super important.
        for (int k = 0; k <= K; ++k) {
            dp[M - 1][N - 1][k] = 0;
            queue<vector<int>> q;
            q.push({ M - 1, N - 1, 0, 0 });
            seen[M - 1][N - 1][k] = 1;
            while (q.size()) {
                auto pos = q.front();
                q.pop();
                int x = pos[0], y = pos[1], i = pos[2], val = pos[3];
                dp[x][y][k] = val;
                seen[x][y][k] = 1;
                for (auto &dir : dirs) {
                    int a = x + dir[0], b = y + dir[1];
                    if (a < 0 || b < 0 || a >= M || b >= N || seen[a][b][k] || i + (G[x][y] == 1) > k) continue;
                    seen[a][b][k] = 1;
                    q.push({ a, b, i + (G[x][y] == 1), val + 1 });
                }
            }
        }
        return dp[0][0][K] >= 0x3f3f3f3f ? -1 : dp[0][0][K];
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MNK)
// Ref: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/451787/Python-O(m*n*k)-BFS-Solution-with-Explanation
class Solution {
public:
    int shortestPath(vector<vector<int>>& G, int K) {
        int M = G.size(), N = G[0].size(), seen[40][40][80] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        if (K >= M + N - 3) return M + N - 2;
        queue<vector<int>> q;
        q.push({ 0, 0, K, 0 });
        seen[0][0][K] = 1;
        while (q.size()) {
            auto pos = q.front();
            q.pop();
            int x = pos[0], y = pos[1], r = pos[2], val = pos[3];
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || b < 0 || a >= M || b >= N) continue;
                int rr = r - (G[x][y] == 1);
                if (rr < 0 || seen[a][b][rr]) continue;
                if (a == M - 1 && b == N - 1) return val + 1;
                seen[a][b][rr] = 1;
                q.push({ a, b, rr, val + 1 });
            }
        }
        return -1;
    }
};
```

## Solution 3. DFS

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

## Solution 4. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: github.com/lzl124631x
// Time: O(MN * min(K, M + N))
// Space: O(MNK)
class Solution {
    typedef tuple<int, int, int, int> Point; // distance, x, y, bomb
public:
    int shortestPath(vector<vector<int>>& G, int K) {
        int M = G.size(), N = G[0].size(), dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, ans = INT_MAX;
        vector<vector<vector<bool>>> seen(M, vector<vector<bool>>(N, vector<bool>(K + 1)));
        queue<Point> q;
        q.emplace(0, 0, 0, K);
        seen[0][0][K] = true;
        while (q.size()) {
            auto [d, x, y, bomb] = q.front();
            q.pop();
            if (x == M - 1 && y == N - 1) return d;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N) continue;
                int nextDist = 1 + d, nextBomb = bomb - (G[a][b] == 1);
                if (nextBomb == -1 || seen[a][b][nextBomb]) continue;
                seen[a][b][nextBomb] = true;
                q.emplace(nextDist, a, b, nextBomb);
            }
        }
        return -1;
    }
};
```

## Note

* For shortest path problem, BFS should be the first choice.
* Initially my solution got TLE just because I didn't add the check `if (K >= M + N - 3) return M + N - 2;`. This line reduces the time complexity from `O(M^2 * N^2)` to `O(MN * min(K, M + N))`.