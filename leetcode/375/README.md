# [375. Guess Number Higher or Lower II (Medium)](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)

<p>We are playing the Guess Game. The game is as follows:</p>

<p>I pick a number from <strong>1</strong> to <strong>n</strong>. You have to guess which number I picked.</p>

<p>Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.</p>

<p>However, when you guess a particular number x, and you guess wrong, you pay <b>$x</b>. You win the game when you guess the number I picked.</p>

<p><b>Example:</b></p>

<pre>n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
</pre>

<p>Given a particular <strong>n ≥ 1</strong>, find out how much money you need to have to guarantee a <b>win</b>.</p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Minimax](https://leetcode.com/tag/minimax/)

**Similar Questions**:
* [Flip Game II (Medium)](https://leetcode.com/problems/flip-game-ii/)
* [Guess Number Higher or Lower (Easy)](https://leetcode.com/problems/guess-number-higher-or-lower/)
* [Can I Win (Medium)](https://leetcode.com/problems/can-i-win/)
* [Find K Closest Elements (Medium)](https://leetcode.com/problems/find-k-closest-elements/)

## Solution 1. DP Top-down

Let `dp[i][j]` be the answer to the subproblem with number range `[i, j]`.

```
dp[i][j] = min( k + max(dp[i][k-1], dp[k+1][j]) | i <= k <= j )
dp[i][j] = 0   where i >= j
```

```cpp
// OJ: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int solve(vector<vector<int>> &dp, int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j]) return dp[i][j];
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; ++k) dp[i][j] = min(dp[i][j], k + max(solve(dp, i, k - 1), solve(dp, k + 1, j)));
        return dp[i][j];
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        return solve(dp, 1, n);
    }
};
```

## Solution 2. DP Bottom-up

```cpp
// OJ: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], k + max(k == i ? 0 : dp[i][k - 1], k == j ? 0 : dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
```