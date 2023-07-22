# [688. Knight Probability in Chessboard (Medium)](https://leetcode.com/problems/knight-probability-in-chessboard)

<p>On an <code>n x n</code> chessboard, a knight starts at the cell <code>(row, column)</code> and attempts to make exactly <code>k</code> moves. The rows and columns are <strong>0-indexed</strong>, so the top-left cell is <code>(0, 0)</code>, and the bottom-right cell is <code>(n - 1, n - 1)</code>.</p>
<p>A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.</p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="width: 300px; height: 300px;">
<p>Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.</p>
<p>The knight continues moving until it has made exactly <code>k</code> moves or has moved off the chessboard.</p>
<p>Return <em>the probability that the knight remains on the board after it has stopped moving</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3, k = 2, row = 0, column = 0
<strong>Output:</strong> 0.06250
<strong>Explanation:</strong> There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 1, k = 0, row = 0, column = 0
<strong>Output:</strong> 1.00000
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 25</code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
	<li><code>0 &lt;= row, column &lt;= n - 1</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Out of Boundary Paths (Medium)](https://leetcode.com/problems/out-of-boundary-paths/)

## Solution 1. DP

Denote the result as `F(N, K, r, c)`.

For `K = 0`:
```
F(N, K, r, c) = 1     If (r, c) is on board.
                0     otherwise.
```

For `K > 0`:
```
F(N, K, r, c) = sum(F(N, K - 1, x, y)) / 8      where (x, y) are all the points reachable from (r, c)
```

We can use this recurrence relation to solve the problem.

```cpp
// OJ: https://leetcode.com/problems/knight-probability-in-chessboard/
// Author: github.com/lzl124631x
// Time: O(KN^2)
// Space: O(N^2)
class Solution {
private:
    int dirs[8][2] = {{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> m(N, vector<double>(N, 1));
        while (K-- > 0) {
            vector<vector<double>> next(N, vector<double>(N, 0));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (auto &dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x < 0 || x >= N || y < 0 || y >= N) continue;
                        next[i][j] += m[x][y];
                    }
                    next[i][j] /= 8;
                }
            }
            m = next;
        }
        return m[r][c];
    }
};
```

## Solution 2. DP

Let `dp[k][x][y]` be the possibility of reaching `(x,y)` with `k` steps.

```
dp[0][row][column] = 1

dp[k][x][y] = sum( dp[k-1][a][b] | (a, b) is one move away from (x, y) ) / 8
```

The answer is `sum( dp[K][x][y] )` for all `(x, y)` on board.

```cpp
// OJ: https://leetcode.com/problems/knight-probability-in-chessboard
// Author: github.com/lzl124631x
// Time: O(KN^2)
// Space: O(N^2)
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        int dirs[8][2] = {{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
        vector<vector<double>> A(n, vector<double>(n));
        A[row][column] = 1;
        for (int i = 0; i < k; ++i) {
            vector<vector<double>> next(n, vector<double>(n));
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (A[x][y] == 0) continue;
                    for (auto &[dx, dy] : dirs) {
                        int a = x + dx, b = y + dy;
                        if (a < 0 || a >= n || b < 0 || b >= n) continue;
                        next[a][b] += A[x][y] / 8;
                    }
                }
            }
            swap(A, next);
        }
        double ans = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                ans += A[x][y];
            }
        }
        return ans;
    }
};
```