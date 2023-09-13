# [1139. Largest 1-Bordered Square (Medium)](https://leetcode.com/problems/largest-1-bordered-square/)

<p>Given a 2D <code>grid</code> of <code>0</code>s and <code>1</code>s, return the number of elements in&nbsp;the largest <strong>square</strong>&nbsp;subgrid that has all <code>1</code>s on its <strong>border</strong>, or <code>0</code> if such a subgrid&nbsp;doesn't exist in the <code>grid</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> 9
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,0,0]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length &lt;= 100</code></li>
	<li><code>1 &lt;= grid[0].length &lt;= 100</code></li>
	<li><code>grid[i][j]</code> is <code>0</code> or <code>1</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Matrix Prefix Sum

```cpp
// OJ: https://leetcode.com/problems/largest-1-bordered-square/
// Author: github.com/lzl124631x
// Time: O(MN * min(M, N))
// Space: O(MN)
class Solution {
    inline int getCount(vector<vector<int>> &cnt, int a, int b, int c, int d) {
        return cnt[c + 1][d + 1] - cnt[a][d + 1] - cnt[c + 1][b] + cnt[a][b];
    }
public:
    int largest1BorderedSquare(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size(), ans = 0;
        vector<vector<int>> cnt(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            int sum = 0;
            for (int j = 0; j < N; ++j) {
                sum += G[i][j];
                cnt[i + 1][j + 1] = cnt[i][j + 1] + sum;
            }
        }
        for (int a = 0; a < M; ++a) {
            for (int b = 0; b < N; ++b) {
                if (G[a][b] == 0) continue;
                ans = max(ans, 1);
                for (int len = 2; a + len - 1 < M && b + len - 1 < N; ++len) {
                    int c = a + len - 1, d = b + len - 1;
                    if (getCount(cnt, a, b, c, d) - getCount(cnt, a + 1, b + 1, c - 1, d - 1) != (c - a) * 2 + (d - b) * 2) continue;
                    ans = max(ans, len * len);
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. Prefix Sum per Row and Column

```cpp
// OJ: https://leetcode.com/problems/largest-1-bordered-square/
// Author: github.com/lzl124631x
// Time: O(MN * min(M, N))
// Space: O(MN)
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size(), ans = 0;
        vector<vector<int>> row(M, vector<int>(N + 1)), col(M + 1, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) row[i][j + 1] = row[i][j] + G[i][j];
        }
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) col[i + 1][j] = col[i][j] + G[i][j];
        }
        for (int a = 0; a < M; ++a) {
            for (int b = 0; b < N; ++b) {
                for (int len = 1; a + len - 1 < M && b + len - 1 < N; ++len) {
                    int c = a + len - 1, d = b + len - 1;
                    if (G[a][d] == 0 || G[c][b] == 0) break;
                    if (row[c][d + 1] - row[c][b] != len || col[c + 1][d] - col[a][d] != len) continue;
                    ans = max(ans, len * len);
                }
            }
        }
        return ans;
    }
};
```

Optimizations based on the above solution:

* The row and column indexes `a` and `b` can ends at `M - ans` and `N - ans`. Greater row/column indexes are impossible to get better answer.
* Instead of scanning from `len = 1` every time, start from `len = {previous longest valid length} + 1`.

```cpp
// OJ: https://leetcode.com/problems/largest-1-bordered-square/
// Author: github.com/lzl124631x
// Time: O(MN * min(M, N))
// Space: O(MN)
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size(), ans = 0;
        vector<vector<int>> row(M, vector<int>(N + 1)), col(M + 1, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) row[i][j + 1] = row[i][j] + G[i][j];
        }
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) col[i + 1][j] = col[i][j] + G[i][j];
        }
        for (int a = 0; a < M - ans; ++a) {
            for (int b = 0; b < N - ans; ++b) {
                for (int len = ans + 1; a + len - 1 < M && b + len - 1 < N; ++len) {
                    int c = a + len - 1, d = b + len - 1;
                    if (row[a][d + 1] - row[a][b] != len || col[c + 1][b] - col[a][b] != len) break;
                    if (row[c][d + 1] - row[c][b] != len || col[c + 1][d] - col[a][d] != len) continue;
                    ans = max(ans, len);
                }
            }
        }
        return ans * ans;
    }
};
```