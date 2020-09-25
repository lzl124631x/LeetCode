# [1594. Maximum Non Negative Product in a Matrix (Medium)](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)

<p>You are given a&nbsp;<code>rows x cols</code>&nbsp;matrix&nbsp;<code>grid</code>.&nbsp;Initially, you&nbsp;are located at the top-left&nbsp;corner <code>(0, 0)</code>,&nbsp;and in each step, you can only <strong>move right&nbsp;or&nbsp;down</strong> in the matrix.</p>

<p>Among all possible paths starting from the top-left corner&nbsp;<code>(0, 0)</code>&nbsp;and ending in the bottom-right corner&nbsp;<code>(rows - 1, cols - 1)</code>, find the path with the&nbsp;<strong>maximum non-negative product</strong>. The product of a path is the product of all integers in the grid cells visited along the path.</p>

<p>Return the&nbsp;<em>maximum non-negative product&nbsp;<strong>modulo</strong>&nbsp;</em><code>10<sup>9</sup>&nbsp;+ 7</code>.&nbsp;<em>If the maximum product is <strong>negative</strong> return&nbsp;</em><code>-1</code>.</p>

<p><strong>Notice that the modulo is performed after getting the maximum product.</strong></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[-1,-2,-3],
&nbsp;              [-2,-3,-3],
&nbsp;              [-3,-3,-2]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[<strong>1</strong>,-2,1],
&nbsp;              [<strong>1</strong>,<strong>-2</strong>,1],
&nbsp;              [3,<strong>-4</strong>,<strong>1</strong>]]
<strong>Output:</strong> 8
<strong>Explanation:</strong> Maximum non-negative product is in bold (1 * 1 * -2 * -4 * 1 = 8).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[<strong>1</strong>, 3],
&nbsp;              [<strong>0</strong>,<strong>-4</strong>]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Maximum non-negative product is in bold (1 * 0 * -4 = 0).
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> grid = [[ <strong>1</strong>, 4,4,0],
&nbsp;              [<strong>-2</strong>, 0,0,1],
&nbsp;              [ <strong>1</strong>,<strong>-1</strong>,<strong>1</strong>,<strong>1</strong>]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Maximum non-negative product is in bold (1 * -2 * 1 * -1 * 1 * 1 = 2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rows, cols &lt;= 15</code></li>
	<li><code>-4 &lt;= grid[i][j] &lt;= 4</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxProductPath(vector<vector<int>>& G) {
        long ans = 0, mod = 1e9+7, M = G.size(), N = G[0].size();
        vector<vector<pair<long, long>>> dp(M + 1, vector<pair<long, long>>(N + 1, { INT_MAX, INT_MIN })); // min, max
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 && j == 0) dp[i][j] =  {G[i][j], G[i][j]};
                if (i != 0) {
                    dp[i][j].first = min(dp[i - 1][j].first * G[i][j], dp[i - 1][j].second * G[i][j]);
                    dp[i][j].second = max(dp[i - 1][j].first * G[i][j], dp[i - 1][j].second * G[i][j]);
                }
                if (j != 0) {
                    dp[i][j].first = min({ dp[i][j].first, dp[i][j - 1].first * G[i][j], dp[i][j - 1].second * G[i][j] });
                    dp[i][j].second = max({ dp[i][j].second, dp[i][j - 1].first * G[i][j], dp[i][j - 1].second * G[i][j] });
                }
            }
        }
        return dp[M - 1][N - 1].second < 0 ? -1 : (dp[M - 1][N - 1].second % mod);
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maxProductPath(vector<vector<int>>& G) {
        long ans = 0, mod = 1e9+7, M = G.size(), N = G[0].size();
        vector<pair<long, long>> dp(N + 1); // min, max
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                long mn = INT_MAX, mx = INT_MIN;
                if (i == 0 && j == 0) mn = mx = G[i][j];
                if (i != 0) {
                    mn = min(dp[j].first * G[i][j], dp[j].second * G[i][j]);
                    mx = max(dp[j].first * G[i][j], dp[j].second * G[i][j]);
                }
                if (j != 0) {
                    mn = min({ mn, dp[j - 1].first * G[i][j], dp[j - 1].second * G[i][j] });
                    mx = max({ mx, dp[j - 1].first * G[i][j], dp[j - 1].second * G[i][j] });
                }
                dp[j] = { mn, mx };
            }
        }
        return dp[N - 1].second < 0 ? -1 : (dp[N - 1].second % mod);
    }
};
```