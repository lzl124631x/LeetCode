# [188. Best Time to Buy and Sell Stock IV (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)

<p>Say you have an array for which the <i>i<span style="font-size: 10.8333px;">-</span></i><span style="font-size: 10.8333px;">th</span>&nbsp;element is the price of a given stock on day <i>i</i>.</p>

<p>Design an algorithm to find the maximum profit. You may complete at most <b>k</b> transactions.</p>

<p><b>Note:</b><br>
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,4,1], k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [3,2,6,5,0,3], k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
&nbsp;            Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
</pre>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Best Time to Buy and Sell Stock II (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
* [Best Time to Buy and Sell Stock III (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

## Solution 1. DP

See my note [123. Best Time to Buy and Sell Stock III](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III) for detailed explanations.

Here I just use the result in that note.

Let `dp[k][i]` be the maximum profit using at most `k` transactions, on `i`-th day.

```
dp[k][i] = max(
                dp[k][i - 1],
                prices[i] + max( dp[k - 1][j - 1] - prices[j] | 0 <= j < i )
              )
           where i >= 1

dp[i][0] = dp[0][i] = 0
```

The most naive implementation of this formula will get TLE.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN^2)
// Space: O(KN)
// NOTE: this will get TLE
class Solution {
public:
    int maxProfit(int K, vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        K = min(K, N / 2);
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for (int k = 1; k <= K; ++k) {
            for (int i = 1; i < N; ++i) {
                int maxVal = INT_MIN;
                for (int j = 0; j < i; ++j) maxVal = max(maxVal, dp[k - 1][j] - A[j]);
                dp[k][i + 1] = max(dp[k][i], A[i] + maxVal);
            }
        }
        return dp[K][N];
    }
};
```

We can avoid repetitively computing `maxVal` by using the deduction `maxVal[k][i] = max(maxVal[k][i - 1], dp[k - 1][i - 1] - A[i])`.

Since `maxVal` represents the max profit using at most `k` transactions (the last `k`-th transaction only contains the purchase) if we buy on `i`-th day, I rename it to `buy`.

So
```
dp[k][i] = max(dp[k][i - 1], prices[i] + buy[k][i])

where buy[k][i] = max(buy[k][i - 1], dp[k - 1][i - 1] - A[i])
    and i >= 0

dp[i][0] = dp[0][i] = 0
```

Since buying and selling at the same day doesn't make sense, we can do at most `N / 2` transactions given `N` days, `K` should be capped at `N / 2`.

When `K >= N / 2`, we can perform as many transactions as possible. In this special case we can do one pass with `O(N)` time instead of the normal `O(KN)` way.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
class Solution {
public:
    int maxProfit(int K, vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        if (K >= N / 2) {
           int ans = 0;
            for (int i = 1; i < N; ++i) ans += max(0, A[i] - A[i - 1]);
            return ans;
        }
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for (int k = 1; k <= K; ++k) {
            int buy = INT_MIN;
            for (int i = 0; i < N; ++i) {
                buy = max(buy, dp[k - 1][i] - A[i]);
                dp[k][i + 1] = max(dp[k][i], A[i] + buy);
            }
        }
        return dp[K][N];
    }
};
```

## Solution 2. DP Space Optimization

From Solution 1:

```
dp[k][i] = max(dp[k][i - 1], prices[i] + buy[k][i])

where buy[k][i] = max(buy[k][i - 1], dp[k - 1][i - 1] - A[i])
    and i >= 0

dp[i][0] = dp[0][i] = 0
```

we can see the following dependency:

```
dp[k-1][i-1]

                 \

dp[k][i-1]   -- dp[k][i]
```

So we can reduce the `dp` array from `K * N` to `2 * N`.

Another tiny optimization is that, if the result using `k` transactions is the same as the result using `k-1` transactions, using more transactions can't make more profit, we've found the best result.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(N)
class Solution {
public:
    int maxProfit(int K, vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), prev = 0;
        if (K >= N / 2) {
           int ans = 0;
            for (int i = 1; i < N; ++i) ans += max(0, A[i] - A[i - 1]);
            return ans;
        }
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int k = 1; k <= K; ++k) {
            int buy = INT_MIN;
            for (int i = 0; i < N; ++i) {
                buy = max(buy, dp[(k - 1) % 2][i] - A[i]);
                dp[k % 2][i + 1] = max(dp[k % 2][i], A[i] + buy);
            }
            if (dp[k % 2][N] == prev) return prev;
            prev = dp[k % 2][N];
        }
        return prev;
    }
};
```

If we flip `i` and `k`, we can use the formula in my note [123. Best Time to Buy and Sell Stock III](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III)

```
dp[i][k] = max(dp[i - 1][k], prices[i] + buy[i][k])

where buy[i][k] = max(m[i - 1][k], dp[i - 1][k - 1] - A[i])
    and i >= 0

buy[-1][k] = -INF
dp[i][0] = dp[0][i] = 0
```

Since `dp[i][k]` means the max profit with at most `k` transactions if we sell on `i`-th day, I rename the array `dp` to `sell`.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(K)
class Solution {
public:
    int maxProfit(int K, vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        if (K >= N / 2) {
           int ans = 0;
            for (int i = 1; i < N; ++i) ans += max(0, A[i] - A[i - 1]);
            return ans;
        }
        vector<int> sell(K + 1), buy(K + 1, INT_MIN);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k <= K; ++k) {
                buy[k] = max(buy[k], sell[k - 1] - A[i]);
                sell[k] = max(sell[k], A[i] + buy[k]);
            }
        }
        return sell[K];
    }
};
```