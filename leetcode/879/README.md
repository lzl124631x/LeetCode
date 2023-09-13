# [879. Profitable Schemes (Hard)](https://leetcode.com/problems/profitable-schemes/)

<p>There is a group of <code>n</code> members, and a list of various crimes they could commit. The <code>i<sup>th</sup></code> crime generates a <code>profit[i]</code> and requires <code>group[i]</code> members to participate in it. If a member participates in one crime, that member can't participate in another crime.</p>

<p>Let's call a <strong>profitable scheme</strong> any subset of these crimes that generates at least <code>minProfit</code> profit, and the total number of members participating in that subset of crimes is at most <code>n</code>.</p>

<p>Return the number of schemes that can be chosen. Since the answer may be very large, <strong>return it modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5, minProfit = 3, group = [2,2], profit = [2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
<strong>Output:</strong> 7
<strong>Explanation:</strong> To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= minProfit &lt;= 100</code></li>
	<li><code>1 &lt;= group.length &lt;= 100</code></li>
	<li><code>1 &lt;= group[i] &lt;= 100</code></li>
	<li><code>profit.length == group.length</code></li>
	<li><code>0 &lt;= profit[i] &lt;= 100</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Top-down DP

Let `dp(i,j,k)` be the number of profitable schemas using crimes whose indexes are in range `[i, M)`, `j` member allowance, and `k` as profit goal (i.e. minimum total profit).

```
dp(i, j, k) = dp(i+1, j, k)                    // skip crime `i`
              dp(i+1, j-group[i], k-profit[i]) // use crime `i`
```

Special cases:
* `dp(i, j, k) = 0` if `j < 0` (no member allowance)
* If `i == M`, `dp(i, j, k) = k <= 0 ? 1 : 0` (If profit goal `<= 0`, it's achievable)

Note that when `k < 0`, we need to do `k = max(0, k)` because negative profit goal has the same schema as `0` profit goal.

```cpp
// OJ: https://leetcode.com/problems/profitable-schemes/
// Author: github.com/lzl124631x
// Time: O(MNP) where `M` is the number of crimes, `N` is the number of members, and `P` is `minProfit`
// Space: O(MNP)
class Solution {
public:
    int profitableSchemes(int N, int minProfit, vector<int>& group, vector<int>& profit) {
        long mod = 1e9 + 7, M = group.size(), dp[101][101][101] = {}; // crime, members, profit
        memset(dp, -1, sizeof(dp));
        function<long(int, int, int)> dfs = [&](int i, int j, int k) {
            if (j < 0) return 0L; // If we don't have enough members, return 0
            if (i == M) return k <= 0 ? 1L : 0L; // If the profit goal is not positive, it's achievable and we return 1; otherwise, return 0.
            k = max(0, k); // Negative profit goal is the same as 0 profit goal
            if (dp[i][j][k] != -1) return dp[i][j][k];
            return dp[i][j][k] = (dfs(i + 1, j, k) + dfs(i + 1, j - group[i], k - profit[i])) % mod; // skip crime `i` or pick crime `i`.
        };
        return dfs(0, N, minProfit);
    }
};
```

## Solution 2. Bottom-up DP

```cpp
// OJ: https://leetcode.com/problems/profitable-schemes/
// Author: github.com/lzl124631x
// Time: O(MNP)
// Space: O(MNP)
class Solution {
public:
    int profitableSchemes(int N, int minProfit, vector<int>& group, vector<int>& profit) {
        long mod = 1e9 + 7, M = group.size(), dp[101][101][101] = {}; // crime, members, profit
        for (int j = 0; j <= N; ++j) dp[0][j][0] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j <= N; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    long val = dp[i][j][k];
                    if (j - group[i] >= 0)
                        val = (val + dp[i][j - group[i]][max(0, k - profit[i])]) % mod;
                    dp[i + 1][j][k] = val;
                }
            }
        }
        return dp[M][N][minProfit];
    }
};
```

Since `dp[i+1]` values only depends on `dp[i]`, we can reduce the space complexity to `O(NP)`.

```cpp
// OJ: https://leetcode.com/problems/profitable-schemes/
// Author: github.com/lzl124631x
// Time: O(MNP)
// Space: O(NP)
class Solution {
public:
    int profitableSchemes(int N, int minProfit, vector<int>& group, vector<int>& profit) {
        long mod = 1e9 + 7, M = group.size(), dp[101][101] = {}, tmp[101][101] = {}; // crime, members, profit
        for (int j = 0; j <= N; ++j) dp[j][0] = 1;
        for (int i = 0; i < M; ++i) {
            swap(tmp, dp);
            for (int j = 0; j <= N; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    long val = tmp[j][k];
                    if (j - group[i] >= 0)
                        val = (val + tmp[j - group[i]][max(0, k - profit[i])]) % mod;
                    dp[j][k] = val;
                }
            }
        }
        return dp[N][minProfit];
    }
};
```