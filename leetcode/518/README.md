# [518. Coin Change II (Medium)](https://leetcode.com/problems/coin-change-ii)

<p>You are given an integer array <code>coins</code> representing coins of different denominations and an integer <code>amount</code> representing a total amount of money.</p>

<p>Return <em>the number of combinations that make up that amount</em>. If that amount of money cannot be made up by any combination of the coins, return <code>0</code>.</p>

<p>You may assume that you have an infinite number of each kind of coin.</p>

<p>The answer is <strong>guaranteed</strong> to fit into a signed <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> amount = 5, coins = [1,2,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> amount = 3, coins = [2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> the amount of 3 cannot be made up just with coins of 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> amount = 10, coins = [10]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 300</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 5000</code></li>
	<li>All the values of <code>coins</code> are <strong>unique</strong>.</li>
	<li><code>0 &lt;= amount &lt;= 5000</code></li>
</ul>


**Companies**:
[Uber](https://leetcode.com/company/uber), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Cisco](https://leetcode.com/company/cisco), [Microsoft](https://leetcode.com/company/microsoft), [eBay](https://leetcode.com/company/ebay), [Adobe](https://leetcode.com/company/adobe), [Citadel](https://leetcode.com/company/citadel)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Maximum Value of K Coins From Piles (Hard)](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles)
* [Number of Ways to Earn Points (Hard)](https://leetcode.com/problems/number-of-ways-to-earn-points)
* [Count of Sub-Multisets With Bounded Sum (Hard)](https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum)

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