# [1411. Number of Ways to Paint N × 3 Grid (Hard)](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/)

<p>You have a <code>grid</code> of size <code>n x 3</code> and you want to paint each cell of the grid with exactly&nbsp;one of the three colours: <strong>Red</strong>, <strong>Yellow</strong> or <strong>Green</strong>&nbsp;while making sure that no two adjacent cells have&nbsp;the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).</p>

<p>You are given <code>n</code> the number of rows of the grid.</p>

<p>Return <em>the number of ways</em> you can paint this <code>grid</code>. As the answer may grow large, the answer <strong>must be</strong> computed modulo&nbsp;<code>10^9 + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 12
<strong>Explanation:</strong> There are 12 possible way to paint the grid as shown:
<img alt="" src="https://assets.leetcode.com/uploads/2020/03/26/e1.png" style="width: 450px; height: 289px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 54
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 246
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 7
<strong>Output:</strong> 106494
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 5000
<strong>Output:</strong> 30228214
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>grid[i].length == 3</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP with State Compression

Once we know the state of the previous row and the row number, the number of the ways for the rest of the rows are fixed.

So we just need to store the mapping from the state to the number of ways.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574912/JavaC%2B%2B-DFS-Memoization-with-Picture-Clean-code
class Solution {
    int memo[5001][4][4][4] = {0}, mod = 1e9+7;
    int dp(int n, int a, int b, int c) {
        if (n == 0) return 1;
        if (memo[n][a][b][c]) return memo[n][a][b][c];
        int ans = 0, colors[3] = {1, 2, 3};
        for (int aa : colors) {
            if (aa == a) continue;
            for (int bb : colors) {
                if (bb == b || bb == aa) continue;
                for (int cc : colors) {
                    if (cc == c || cc == bb) continue;
                    ans = (ans + dp(n - 1, aa, bb, cc)) % mod;
                }
            }
        }
        return memo[n][a][b][c] = ans;
    }
public:
    int numOfWays(int n) {
        return dp(n, 0, 0, 0);
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574943/Java-Detailed-Explanation-with-Graph-Demo-DP-Easy-Understand
class Solution {
    typedef long long LL;
public:
    int numOfWays(int n) {
        LL mod = 1e9+7, color2 = 6, color3 = 6;
        for (int i = 2; i <= n; ++i) {
            LL c3 = (2 * color3 + 2 * color2) % mod;
            LL c2 = (2 * color3 + 3 * color2) % mod;
            color2 = c2, color3 = c3;
        }
        return (color2 + color3) % mod;
    }
};
```

## Solution 3. DP with Matrix Multiplication

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/575485/C%2B%2BPython-O(logN)-Time
class Solution {
    typedef long long LL;
    int mod = 1e9+7;
    vector<vector<LL>> mul(vector<vector<LL>> &A, vector<vector<LL>> &B) {
        int N = A.size(), L = B.size(), M = B[0].size();
        vector<vector<LL>> C(N, vector<LL>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < L; ++k) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }
public:
    int numOfWays(int n) {
        vector<vector<LL>> ans = {{6, 6}}, M = {{3, 2}, {2, 2}};
        for (--n; n; n >>= 1, M = mul(M, M)) {
            if (n % 2) ans = mul(ans, M);
        }
        return (ans[0][0] + ans[0][1]) % mod;
    }
};
```