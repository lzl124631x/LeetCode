# [518. Coin Change 2 (Medium)](https://leetcode.com/problems/coin-change-2/)

<p>You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> amount = 5, coins = [1, 2, 5]
<b>Output:</b> 4
<b>Explanation:</b> there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> amount = 3, coins = [2]
<b>Output:</b> 0
<b>Explanation:</b> the amount of 3 cannot be made up just with coins of 2.
</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> amount = 10, coins = [10] 
<b>Output:</b> 1
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<p>You can assume that</p>

<ul>
	<li>0 &lt;= amount &lt;= 5000</li>
	<li>1 &lt;= coin &lt;= 5000</li>
	<li>the number of coins is less than 500</li>
	<li>the answer is guaranteed to fit into signed 32-bit integer</li>
</ul>


## Solution 1. DFS + Memo

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(A * C^2)
// Space: O(AC)
class Solution {
private:
    unordered_map<int, int> memo;
    int change(int amount, vector<int>& coins, int start) {
        if (!amount) return 1;
        if (start >= coins.size()) return 0;
        int key = amount * 1000 + start;
        if (memo.find(key) != memo.end()) return memo[key];
        int ans = 0;
        for (int i = start; i < coins.size(); ++i) {
            if (amount >= coins[i]) ans += change(amount - coins[i], coins, i);
        }
        return memo[key] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        return change(amount, coins, 0);
    }
};
```

## Solution 2. DP (Unbounded knapsack problem), Naive version

This is a typical unbounded knapsack problem where you can pick item unlimited times (unbounded).

Let `dp[i+1][T]` be the ways to form `T` value using `A[0]` ... `A[i]`.

```
dp[i+1][T]      = dp[i][T] + dp[i][T-A[i]] + dp[i][T-2*A[i]] ...

dp[i][0] = 1
```

We can directly apply this formula.

This is the naive solution, and in the next solution we find way to optimize it.

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(N^2 * T)
// Space: O(NT)
class Solution {
public:
    int change(int T, vector<int>& A) {
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(T + 1));
        for (int i = 0; i <= N; ++i) dp[i][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int t = 1; t <= T; ++t) {
                for (int k = 0; t - k * A[i] >= 0; ++k) {
                    dp[i + 1][t] += dp[i][t - k * A[i]];
                }
            }
        }
        return dp[N][T];
    }
};
```

## Solution 3. DP (Unbounded knapsack problem)

Let `dp[i+1][T]` be the ways to form `T` value using `A[0]` ... `A[i]`.

```
dp[i+1][T]      = dp[i][T] + dp[i][T-A[i]] + dp[i][T-2*A[i]] ...

dp[i+1][T-A[i]] =            dp[i][T-A[i]] + dp[i][T-2*A[i]] ...

// so
dp[i+1][T] = dp[i+1][T-A[i]] + dp[i][T]

dp[i][0] = 1
```

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(NT)
class Solution {
public:
    int change(int T, vector<int>& A) {
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(T + 1));
        for (int i = 0; i <= N; ++i) dp[i][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int t = 1; t <= T; ++t) {
                dp[i + 1][t] = (t - A[i] >= 0 ? dp[i + 1][t - A[i]] : 0) + dp[i][t];
            }
        }
        return dp[N][T];
    }
};
```

## Solution 4. DP (Unbounded knapsack problem) with Space Optimization

Since `dp[i+1][T]` only depends on `dp[i+1][T-A[i]]` and `dp[i][T]`, we can reduce the `dp` array from `N * T` to `1 * T`.

```cpp
// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
public:
    int change(int T, vector<int>& A) {
        int N = A.size();
        vector<int> dp(T + 1);
        dp[0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int t = A[i]; t <= T; ++t) {
                dp[t] += dp[t - A[i]];
            }
        }
        return dp[T];
    }
};
```