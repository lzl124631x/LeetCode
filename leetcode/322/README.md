# [322. Coin Change (Medium)](https://leetcode.com/problems/coin-change/)

<p>You are given an integer array <code>coins</code> representing coins of different denominations and an integer <code>amount</code> representing a total amount of money.</p>

<p>Return <em>the fewest number of coins that you need to make up that amount</em>. If that amount of money cannot be made up by any combination of the coins, return <code>-1</code>.</p>

<p>You may assume that you have an infinite number of each kind of coin.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> coins = [1,2,5], amount = 11
<strong>Output:</strong> 3
<strong>Explanation:</strong> 11 = 5 + 5 + 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> coins = [2], amount = 3
<strong>Output:</strong> -1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> coins = [1], amount = 0
<strong>Output:</strong> 0
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> coins = [1], amount = 1
<strong>Output:</strong> 1
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> coins = [1], amount = 2
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 12</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= amount &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Bloomberg](https://leetcode.com/company/bloomberg), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Airbnb](https://leetcode.com/company/airbnb)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Minimum Cost For Tickets (Medium)](https://leetcode.com/problems/minimum-cost-for-tickets/)

## Solution 1. DP

Let `dp[i + 1][t]` be the minimum coins needed to get a total amount of money `t` with the first `i + 1` coins.

```
dp[i + 1][t] = min(
                dp[i][t],                    // don't use A[i]
                dp[i][t - A[i]] + 1,         // use A[i] once
                dp[i][t - A[i] * 2] + 2,     // use A[i] twice
                ...
            )
dp[i + 1][t] = min(dp[i][t], 1 + dp[i + 1][t - A[i]]) where 0 <= i < N
dp[i][0] = 0 where 0 <= i <= N
```

```cpp
// OJ: https://leetcode.com/problems/coin-change/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(NT)
class Solution {
public:
    int coinChange(vector<int>& A, int T) {
        sort(begin(A), end(A), greater<>());
        int N = A.size(), INF = 0x3f3f3f3f, dp[13][10001] = {};
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i <= N; ++i) dp[i][0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int t = 1; t <= T; ++t) {
                dp[i + 1][t] = min(dp[i][t], t - A[i] >= 0 ? 1 + dp[i + 1][t - A[i]] : INF);
            }
        }
        return dp[N][T] == INF ? -1 : dp[N][T];
    }
};
```

Or use 1D array instead.

```cpp
// OJ: https://leetcode.com/problems/coin-change/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
public:
    int coinChange(vector<int>& A, int T) {
        sort(begin(A), end(A), greater<>());
        int N = A.size(), INF = 0x3f3f3f3f, dp[10001] = {}, next[10001] = {};
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            memset(next, 0x3f, sizeof(next));
            next[0] = 0;
            for (int t = 1; t <= T; ++t) {
                next[t] = min(dp[t], t - A[i] >= 0 ? 1 + next[t - A[i]] : INF);
            }
            swap(next, dp);
        }
        return dp[T] == INF ? -1 : dp[T];
    }
};
```

## Solution 2. DP

If we switch the order of `t` and `i`, we can use 1D array directly.

Let `dp[t][i + 1]` be the minimum coins needed to get a total amount of money `t` with the first `i + 1` coins.

```
dp[t][i + 1] = min(
                    dp[t][i],                  // don't use A[i]
                    dp[t - A[i]][i] + 1,       // use A[i] once
                    dp[t - A[i] * 2][i] + 2,   // use A[i] twice
                    ...
                )
dp[t][i + 1] = min(dp[t][i], 1 + dp[t - A[i]][i])   where 0 <= i < N
dp[0][i] = 0 where 0 <= i <= N
```

Let `dp[t]` be the minimum coins needed to get a total amount of money `t` with all coins.

```
dp[t] = dp[t - C] + 1 where C is the last coin's denomination
dp[t] = min( dp[t - A[i]] + 1 | 0 <= i < N && t - A[i] >= 0 )
dp[0] = 0
```

```cpp
// OJ: https://leetcode.com/problems/coin-change/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
public:
    int coinChange(vector<int>& A, int T) {
        int N = A.size(), INF = 0x3f3f3f3f, dp[10001] = {};
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int t = 1; t <= T; ++t) {
            for (int i = 0; i < N; ++i) {
                dp[t] = min(dp[t], t - A[i] >= 0 ? 1 + dp[t - A[i]] : INF);
            }
        }
        return dp[T] == INF ? -1 : dp[T];
    }
};
```