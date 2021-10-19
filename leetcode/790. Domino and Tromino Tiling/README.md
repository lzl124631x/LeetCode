# [790. Domino and Tromino Tiling (Medium)](https://leetcode.com/problems/domino-and-tromino-tiling/)

<p>You have two types of tiles: a <code>2 x 1</code> domino shape and a tromino shape. You may rotate these shapes.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg" style="width: 362px; height: 195px;">
<p>Given an integer n, return <em>the number of ways to tile an</em> <code>2 x n</code> <em>board</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg" style="width: 500px; height: 226px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> The five different ways are show above.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/domino-and-tromino-tiling/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N^2)
class Solution {
public:
    int numTilings(int n) {
        long mod = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = (dp[i - 1][i - 1] + (i - 2 >= 0 ? dp[i - 2][i - 2] + dp[i - 2][i - 1] * 2 : 0)) % mod;
            dp[i - 1][i] = (i - 2 >= 0 ? dp[i - 2][i - 2] + dp[i - 2][i - 1] : 0) % mod;
        }
        return dp[n][n];
    }
};
```

Since `dp[i][i]` and `dp[i-1][i]` only depends on `dp[i-1][i-1], dp[i-2][i-2], dp[i-2][i-1]`, we can reduce the space complexity to `O(1)`.

```cpp
// OJ: https://leetcode.com/problems/domino-and-tromino-tiling/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numTilings(int n) {
        long mod = 1e9 + 7, dp11 = 1, dp21 = 0, dp22 = 0;
        for (int i = 1; i <= n; ++i) {
            int dp00 = (dp11 + dp22 + dp21 * 2) % mod;
            int dp10 = (dp22 + dp21) % mod;
            dp22 = dp11;
            dp11 = dp00;
            dp21 = dp10;
        }
        return dp11;
    }
};
```