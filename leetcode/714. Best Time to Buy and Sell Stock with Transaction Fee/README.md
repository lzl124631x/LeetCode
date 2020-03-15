# [714. Best Time to Buy and Sell Stock with Transaction Fee (Medium)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

<p>Your are given an array of integers <code>prices</code>, for which the <code>i</code>-th element is the price of a given stock on day <code>i</code>; and a non-negative integer <code>fee</code> representing a transaction fee.</p>
<p>You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.  You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)</p>
<p>Return the maximum profit you can make.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> prices = [1, 3, 2, 8, 4, 9], fee = 2
<b>Output:</b> 8
<b>Explanation:</b> The maximum profit can be achieved by:
<li>Buying at prices[0] = 1</li><li>Selling at prices[3] = 8</li><li>Buying at prices[4] = 4</li><li>Selling at prices[5] = 9</li>The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
</pre>
<p></p>

<p><b>Note:</b>
</p><li><code>0 &lt; prices.length &lt;= 50000</code>.</li>
<li><code>0 &lt; prices[i] &lt; 50000</code>.</li>
<li><code>0 &lt;= fee &lt; 50000</code>.</li>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock II (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Solution 1. DP

See my following notes for some reference:
* [123. Best Time to Buy and Sell Stock III (Hard)](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III)
* [188. Best Time to Buy and Sell Stock IV (Hard)](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/188.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20IV)
* [714. Best Time to Buy and Sell Stock with Transaction Fee (Medium)](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/309.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown)

Let `dp[i + 1]` be the max profit on `i`-th day.

If we don't trade on `i`-th day, `dp[i + 1] = dp[i]`.

Otherwise, we buy on some `j`-th day (`j` in `[0, i]`) and sell on `i`-th day:

```
dp[i + 1] = max(prices[i] - prices[j] - fee + dp[j] | 0 <= j <= i)
          = prices[i] - fee + max(dp[j] - prices[i] | 0 <= j <= i)
```

We can define `buy[i] = max(dp[j] - prices[i] | 0 <= j <= i)`, thus:

```
buy[i] = max(buy[i-1], dp[i] - prices[i])    where i >= 0
buy[-1] = -INF
```

In this way we can save the computation for getting `buy[i]`.

```
dp[i + 1] = max(
    dp[i],
    prices[i] - fee + buy[i]
)
buy[i] = max(buy[i-1], dp[i] - prices[i])    where i >= 0
buy[-1] = -INF
```

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxProfit(vector<int>& A, int fee) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN;
        vector<int> dp(N + 1);
        for (int i = 0; i < N; ++i) {
            buy = max(buy, dp[i] - A[i]);
            dp[i + 1] = max(dp[i], A[i] - fee + buy);
        }
        return dp[N];
    }
};
```

## Solution 2. DP with Space Optimization

Since `dp[i + 1]` is only dependent on `dp[i]`, we can use single variable `sell` to keep track of it.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A, int fee) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN, sell = 0;
        for (int i = 0; i < N; ++i) {
            buy = max(buy, sell - A[i]);
            sell = max(sell, A[i] - fee + buy);
        }
        return sell;
    }
};
```