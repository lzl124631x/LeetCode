# [877. Stone Game (Medium)](https://leetcode.com/problems/stone-game/)

<p>Alex and Lee play a game with piles of stones.&nbsp; There are an even number of&nbsp;piles <strong>arranged in a row</strong>, and each pile has a positive integer number of stones <code>piles[i]</code>.</p>

<p>The objective of the game is to end with the most&nbsp;stones.&nbsp; The total number of stones is odd, so there are no ties.</p>

<p>Alex and Lee take turns, with Alex starting first.&nbsp; Each turn, a player&nbsp;takes the entire pile of stones from either the beginning or the end of the row.&nbsp; This continues until there are no more piles left, at which point the person with the most stones wins.</p>

<p>Assuming Alex and Lee play optimally, return <code>True</code>&nbsp;if and only if Alex wins the game.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[5,3,4,5]</span>
<strong>Output: </strong><span id="example-output-1">true</span>
<strong>Explanation: </strong>
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= piles.length &lt;= 500</code></li>
	<li><code>piles.length</code> is even.</li>
	<li><code>1 &lt;= piles[i] &lt;= 500</code></li>
	<li><code>sum(piles)</code> is odd.</li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Bottom-up DP

Let `dp[i][j]` be the maximum difference of stone values, that is, the stones the first player can get minus the stones the second player can get.

```
dp[i][i] = A[i]
dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1])
```

```cpp
// OJ: https://leetcode.com/problems/stone-game/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    bool stoneGame(vector<int>& A) {
        int dp[500][500] = {}, N = A.size();
        for (int i = 0; i < N; ++i) dp[i][i] = A[i];
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]);
        }
        return dp[0][N - 1] > 0;
    }
};
```

## Solution 2. Top-down DP

```cpp
// OJ: https://leetcode.com/problems/stone-game/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int dp[500][500] = {};
    int dfs(vector<int> &A, int i, int j) {
        if (i == j) return A[i];
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = max(A[i] - dfs(A, i + 1, j), A[j] - dfs(A, i, j - 1));
    }
public:
    bool stoneGame(vector<int>& A) {
        return dfs(A, 0, A.size() - 1) > 0;
    }
};
```

## Solution 3.

Notice that the length of `piles` is even. So Alex can always pick piles with either even indices (`piles[0], piles[2], ..., piles[n-2]`) or odd indices (`piles[1], piles[3], ..., piles[n-1]`). Since the total number of stones is odd, so Alex can simply pick the group with more stones.

```cpp
// OJ: https://leetcode.com/problems/stone-game/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```