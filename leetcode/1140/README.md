# [1140. Stone Game II (Medium)](https://leetcode.com/problems/stone-game-ii/)

<p>Alex&nbsp;and Lee continue their&nbsp;games with piles of stones.&nbsp; There are a number of&nbsp;piles&nbsp;<strong>arranged in a row</strong>, and each pile has a positive integer number of stones&nbsp;<code>piles[i]</code>.&nbsp; The objective of the game is to end with the most&nbsp;stones.&nbsp;</p>

<p>Alex and Lee take turns, with Alex starting first.&nbsp; Initially, <code>M = 1</code>.</p>

<p>On each player's turn, that player&nbsp;can take <strong>all the stones</strong> in the <strong>first</strong> <code>X</code> remaining piles, where <code>1 &lt;= X &lt;= 2M</code>.&nbsp; Then, we set&nbsp;<code>M = max(M, X)</code>.</p>

<p>The game continues until all the stones have been taken.</p>

<p>Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> piles = [2,7,9,4,4]
<strong>Output:</strong> 10
<strong>Explanation:</strong>  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 100</code></li>
	<li><code>1 &lt;= piles[i]&nbsp;&lt;= 10 ^ 4</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i][m]` be optimal result Alex can get on subarray `A[i..(N-1)]` and with inital `M = m`. It's a `pair<int, int>` where the first element is the stones Alex can get and the second is the stones Lee can get.

```
dp[i][m] = <p.second + A[i] + ... + A[i + x - 1], p.first>
           where p = dp[i + x][max(m, x)], 1 <= x <= 2m
```

The answer is `dp[0][1].first`.

```cpp
// OJ: https://leetcode.com/problems/stone-game-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    pair<int, int> dp[101][101] = {};
    int presum[101] = {};
    pair<int, int> dfs(vector<int> &A, int i, int M) {
        if (i == A.size()) return {0, 0};
        if (dp[i][M].first != 0) return dp[i][M];
        for (int x = 1; x <= min((int)A.size() - i, 2 * M); ++x) {
            auto p = dfs(A, i + x, max(M, x));
            int sum = presum[i + x] - presum[i];
            if (p.second + sum > dp[i][M].first) dp[i][M] = { p.second + sum, p.first };
        }
        return dp[i][M];
    }
public:
    int stoneGameII(vector<int>& A) {
        partial_sum(begin(A), end(A), presum + 1);
        return dfs(A, 0, 1).first;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/stone-game-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int dp[101][101] = {}, sum[101] = {};
    int dfs(vector<int> &A, int i, int M) {
        if (i == A.size()) return 0;
        if (dp[i][M]) return dp[i][M];
        for (int X = 1; X <= 2 * M && i + X <= A.size(); ++X) dp[i][M] = max(dp[i][M], sum[A.size()] - sum[i] - dfs(A, i + X, max(M, X)));
        return dp[i][M];
    }
public:
    int stoneGameII(vector<int>& A) {
        partial_sum(begin(A), end(A), sum + 1);
        return dfs(A, 0, 1);
    }
};
```