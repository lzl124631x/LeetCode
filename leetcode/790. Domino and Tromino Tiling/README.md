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

Let `dp[i][j]` be the number of ways to tile to the `i`-th column in the first row and `j`-th column in the second row.  The anwer is `dp[n][n]`


There are only 3 possible cases:
* `dp[i][i]`
* `dp[i][i-1]`
* `dp[i-1][i]`

Since `dp[i][i-1]` and `dp[i-1][i]` are symmetrical, we only need to calculate one of them.

For `dp[i][i]`, there are 4 cases to get to it:
1. `dp[i-1][i-1]` when we put a vertical bar at the end
2. `dp[i-1][i-2]` when we put a `┛` at the end
3. `dp[i-2][i-1]` when we put a `┓` at the end
4. `dp[i-2][i-2]` when we put two horizontal bars at the end

After merging case 2 and 3, we get:

```
dp[i][i] = dp[i-1][i-1] + dp[i-1][i-2] * 2 + dp[i-2][i-2]
```

For `dp[i][i-1]`, there are 2 cases:
1. `dp[i-2][i-1]` when we put a horizontal bar in the first row at the end
2. `dp[i-2][i-2]` when we put a `┏` at the end

Since `dp[i-1][i-2] = dp[i-1][i-2]`, we can use `dp[i-1][i-2]` instead in case 1 so that we always only need to compute `dp[i][i-1]`.

```
dp[i][i-1] = dp[i-1][i-2] + dp[i-2][i-2]
```

The trivial case is `dp[0][0] = 1`.

In the implementation, since we need to access `i - 2`, I'll offset the dp values by one so that I don't need to check `i - 2 >= 0`.

```cpp
// OJ: https://leetcode.com/problems/domino-and-tromino-tiling/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N^2)
class Solution {
public:
    int numTilings(int n) {
        long mod = 1e9 + 7;
        vector<vector<long>> dp(n + 2, vector<long>(n + 2));
        dp[1][1] = 1;
        for (int i = 2; i <= n + 1; ++i) {
            dp[i][i] = (dp[i - 1][i - 1] + dp[i - 1][i - 2] * 2 + dp[i - 2][i - 2]) % mod;
            dp[i][i - 1] = (dp[i - 1][i - 2] + dp[i - 2][i - 2]) % mod;
        }
        return dp[n + 1][n + 1];
    }
};
```

Since `dp[i][i]` and `dp[i][i-1]` only depends on `dp[i-1][i-1], dp[i-2][i-2], dp[i-1][i-2]`, we can reduce the space complexity to `O(1)`.

```cpp
// OJ: https://leetcode.com/problems/domino-and-tromino-tiling/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numTilings(int n) {
        long mod = 1e9 + 7, dp11 = 1, dp12 = 0, dp22 = 0;
        for (int i = 1; i <= n; ++i) {
            int dp00 = (dp11 + dp22 + dp12 * 2) % mod;
            int dp01 = (dp22 + dp12) % mod;
            dp22 = dp11;
            dp11 = dp00;
            dp12 = dp01;
        }
        return dp11;
    }
};
```