# [576. Out of Boundary Paths (Medium)](https://leetcode.com/problems/out-of-boundary-paths/)

<p>There is an <code>m x n</code> grid with a ball. The ball is initially at the position <code>[startRow, startColumn]</code>. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply <strong>at most</strong> <code>maxMove</code> moves to the ball.</p>

<p>Given the five integers <code>m</code>, <code>n</code>, <code>maxMove</code>, <code>startRow</code>, <code>startColumn</code>, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png" style="width: 500px; height: 296px;">
<pre><strong>Input:</strong> m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
<strong>Output:</strong> 6
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png" style="width: 500px; height: 293px;">
<pre><strong>Input:</strong> m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= maxMove &lt;= 50</code></li>
	<li><code>0 &lt;= startRow &lt; m</code></li>
	<li><code>0 &lt;= startColumn &lt; n</code></li>
</ul>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Knight Probability in Chessboard (Medium)](https://leetcode.com/problems/knight-probability-in-chessboard/)
* [Execution of All Suffix Instructions Staying in a Grid (Medium)](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/)

## Solution 1. DP Top-down

Let `dp[x][y][k]` be the number of out-of-boundary moves starting from cell `(x, y)` with at most `k` moves.

```
dp[x][y][k] = SUM( dp[a][b][k - 1] | (a,b) is a neighbor of (x, y) )

dp[x][y][k] = 1   if (x, y) is out-of-boundary, and 0 <= k <= maxMoves

dp[x][y][0] = 0   if (x, y) is not out-of-boundary
```

The answer is `dp[startRow][startColumn][maxMove]`.

```cpp
// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(MNK)
// Space: O(MNK)
class Solution {
    long m, n, dp[50][50][51] = {}, dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, mod = 1e9 + 7;
    int dfs(int x, int y, int k) {
        if (x < 0 || x >= m || y < 0 || y >= n) return 1;
        if (k == 0) return 0;
        if (dp[x][y][k] != -1) return dp[x][y][k];
        long cnt = 0;
        for (auto &[dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            cnt = (dfs(a, b, k - 1) + cnt) % mod;
        }
        return dp[x][y][k] = cnt;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return dfs(startRow, startColumn, maxMove);
    }
};
```

## Solution 2. DP Top-down

Let `dp[x][y][k]` be the number of out-of-boundary moves starting from cell `(x, y)` with exactly `k` moves.

```
dp[x][y][k] = SUM( dp[a][b][k - 1] | (a,b) is a neighor of (x,y) )

dp[x][y][0] = 1 if (x,y) is out-of-boundary
dp[x][y][0] = 0 if (x,y) is not out-of-boundary
dp[x][y][k] = 0 if (x,y) is out-of-boundary and k > 0
```

```cpp
// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(MNK)
// Space: O(MNK)
class Solution {
    long m, n, dp[50][50][51] = {}, dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, mod = 1e9 + 7;
    int dfs(int x, int y, int step) {
        int oob = x < 0 || x >= m || y < 0 || y >= n;
        if (step == 0) return oob;
        if (oob) return 0;
        if (dp[x][y][step] != -1) return dp[x][y][step];
        long cnt = 0;
        for (auto &[dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            cnt = (dfs(a, b, step - 1) + cnt) % mod;
        }
        return dp[x][y][step] = cnt;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        long ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= maxMove; ++i) ans = (ans + dfs(startRow, startColumn, i)) % mod;
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(MNK)
// Space: O(MNK)
class Solution {
    long m, n, dp[50][50][51] = {}, dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, mod = 1e9 + 7;
    int dfs(int x, int y, int k) {
        if (dp[x][y][k] != -1) return dp[x][y][k];
        if (k == 1) {
            int cnt = 0;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                cnt += a < 0 || a >= m || b < 0 || b >= n;
            }
            return dp[x][y][k] = cnt;
        }
        long cnt = 0;
        for (auto &[dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            if (a < 0 || a >= m || b < 0 || b >= n) continue;
            cnt = (dfs(a, b, k - 1) + cnt) % mod;
        }
        return dp[x][y][k] = cnt;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        long ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= maxMove; ++i) ans = (ans + dfs(startRow, startColumn, i)) % mod;
        return ans;
    }
};
```

## Solution 3. DP Bottom-up

Let `dp[i][j][k]` be the number of ways to go out of boundary from point `(i, j)` using exactly `k` steps.

```
dp[i][j][k] = SUM( dp[a][b][k - 1] | (a, b) is neighbor of (i, j) )
```

`dp[i][j][1]` is the number of edges the point `(i, j)` touches.

The answer is `SUM( dp[x][y][k] | k = 1, 2, ..., maxMoves )`.

Why not define `dp[i][j][k]` as the number of ways to go out of boundary from point `(i, j)` **with at most `k` steps**?

Because when computing `dp[i][j][k]`, assume we know `dp[i][j][k - 1]`, then we need to compute the ways to go out of boundary with exact `k` steps. So we need the number of ways with **exact `k` steps** any way.

```cpp
// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(MNK)
// Space: O(MN)
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        long dp[50][50][2] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, mod = 1e9 + 7;
        for (int i = 0; i < m; ++i) dp[i][0][1]++, dp[i][n - 1][1]++;
        for (int i = 0; i < n; ++i) dp[0][i][1]++, dp[m - 1][i][1]++;
        long ans = dp[startRow][startColumn][1];
        for (int k = 2; k <= maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = 0;
                    for (auto &[dx, dy] : dirs) {
                        int a = i + dx, b = j + dy;
                        if (a < 0 || a >= m || b < 0 || b >= n) continue;
                        val = (val + dp[a][b][(k - 1) % 2]) % mod;
                    }
                    dp[i][j][k % 2] = val;
                }
            }
            ans = (ans + dp[startRow][startColumn][k % 2]) % mod;
        }
        return ans;
    }
};
```

## Solution 4. DP Bottom-up

Let `dp[i][j][k]` be the number of ways to go from starting point `(x, y)` to point `(i, j)` with exactly `k` steps.

So `dp[x][y][0] = 1`.

```
dp[i][j][k] = SUM( dp[a][b][k - 1] | (a, b) is neighbor of (i, j) )
```

`dp[i][j][k]` should be added into answer if point `(i, j)` is at the boundary (i.e. `i == 0 || i == M - 1 || j == 0 || j == N - 1`) and `0 <= k < maxMoves`.

```cpp
// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(MNK)
// Space: O(MN)
// Ref: https://leetcode.com/problems/out-of-boundary-paths/solution/
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        long dp[50][50][2] = {}, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}, mod = 1e9 + 7, ans = 0;
        dp[startRow][startColumn][0] = 1;
        for (int k = 0; k < maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = dp[i][j][k % 2], cnt = (i == 0) + (i == m - 1) + (j == 0) + (j == n - 1); 
                    ans = (ans + cnt * val % mod) % mod;
                    val = 0;
                    for (auto &[dx, dy] : dirs) {
                        int a = i + dx, b = j + dy;
                        if (a < 0 || a >= m || b < 0 || b >= n) continue;
                        val = (val + dp[a][b][k % 2]) % mod;
                    }
                    dp[i][j][(k + 1) % 2] = val;
                }
            }
        }
        return ans;
    }
};
```