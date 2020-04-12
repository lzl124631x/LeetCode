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
class Solution {
    typedef unsigned long long ULL;
    int N, mod = 1e9+7;
    unordered_map<int, ULL> m;
    int key(vector<vector<int>> &v, int x) {
        if (x == -1) return 0;
        int n = 0;
        for (int i = 0; i < 3; ++i) n = n * 10 + v[x][i];
        n *= 10000;
        return n + x;
    }
    int dp(vector<vector<int>> &v, int x, int y) {
        if (y >= 3) {
            x++;
            y = 0;
        }
        if (x == N) return 1;
        int k = key(v, x - 1);
        if (y == 0 && m.count(k)) return m[k];
        int cnt = 0;
        for (int i = 1; i <= 3; ++i) {
            if ((x > 0 && v[x - 1][y] == i) || (y > 0 && v[x][y - 1] == i)) continue;
            v[x][y] = i;
            cnt = (cnt + dp(v, x, y + 1)) % mod;
        }
        if (y == 0) m[k] = cnt;
        return cnt;
    }
public:
    int numOfWays(int n) {
        N = n;
        vector<vector<int>> v(n, vector<int>(3));
        return dp(v, 0, 0);
    }
};
```