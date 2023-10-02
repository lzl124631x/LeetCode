# [1301. Number of Paths with Max Score (Hard)](https://leetcode.com/problems/number-of-paths-with-max-score/)

<p>You are given a square <code>board</code>&nbsp;of characters. You can move on the board starting at the bottom right square marked with the character&nbsp;<code>'S'</code>.</p>

<p>You need&nbsp;to reach the top left square marked with the character <code>'E'</code>. The rest of the squares are labeled either with a numeric character&nbsp;<code>1, 2, ..., 9</code> or with an obstacle <code>'X'</code>. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.</p>

<p>Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, <strong>taken modulo <code>10^9 + 7</code></strong>.</p>

<p>In case there is no path, return&nbsp;<code>[0, 0]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> board = ["E23","2X2","12S"]
<strong>Output:</strong> [7,1]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> board = ["E12","1X1","21S"]
<strong>Output:</strong> [4,2]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> board = ["E11","XXX","11S"]
<strong>Output:</strong> [0,0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= board.length == board[i].length &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/number-of-paths-with-max-score/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
    const int mod = 1e9 + 7;
public:
    vector<int> pathsWithMaxScore(vector<string>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> zero(2, 0);
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(N, vector<int>(2, 0)));
        dp[(M - 1) % 2][N - 1][1] = 1;
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (A[i][j] == 'S') dp[i % 2][j] = { 0, 1 };
                else if (A[i][j] == 'X') dp[i % 2][j] = zero;
                else {
                    int sum = 0, cnt = 0;
                    auto &B = i + 1 < M ? dp[(i + 1) % 2][j] : zero;
                    auto &R = j + 1 < N ? dp[i % 2][j + 1] : zero;
                    auto &BR = i + 1 < M && j + 1 < N ? dp[(i + 1) % 2][j + 1] : zero;
                    sum = max({ B[0], R[0], BR[0] });
                    if (B[0] == sum) cnt = (cnt + B[1]) % mod;
                    if (R[0] == sum) cnt = (cnt + R[1]) % mod;
                    if (BR[0] == sum) cnt = (cnt + BR[1]) % mod;
                    dp[i % 2][j] = { sum, cnt };
                }
                if (dp[i % 2][j][1] && isdigit(A[i][j])) dp[i % 2][j][0] += A[i][j] - '0';
            }
        }
        return dp[0][0];
    }
};
```