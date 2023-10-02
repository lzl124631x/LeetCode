# [714. Best Time to Buy and Sell Stock with Transaction Fee (Medium)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day, and an integer <code>fee</code> representing a transaction fee.</p>

<p>Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.</p>

<p><strong>Note:</strong> You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> prices = [1,3,2,8,4,9], fee = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> prices = [1,3,7,5,10,3], fee = 3
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt; prices.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt; prices[i], fee &lt; 5 * 10<sup>4</sup></code></li>
</ul>


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
        int buy = INT_MIN, sell = 0;
        for (int n : A) {
            buy = max(buy, sell - n);
            sell = max(sell, n - fee + buy);
        }
        return sell;
    }
};
```

## Solution 3. DP

Another easier way of thinking about this problem:

On day `i`, we have two options: buy or sell.

If we buy, we must buy based on the maximum possible sell result we can get within `[0, i)` days. So `buy[i] = max( sell[j] | 0 <= j < i ) - prices[i]`.

If we sell, we must sell based on the maximum possible buy result we can get within `[0, i)` days. So `sell[i] = max( buy[j] | 0 <= j < i ) + prices[i] - fee`.

We can memoize the maximum of `buy` and `sell` values within day `[0, i)`, and use them to generate the new `buy` and `sell` values on day `i`.

Since `buy` could result in a negative balance, we should use `-INF` as the initial value for `buy`.

Since we won't ever want a negative balance from sell, we should use `0` as the initial value for `sell`.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A, int fee) {
        long buy = INT_MIN, sell = 0;
        for (int n : A) {
            long buy2 = max(buy, sell - n);
            long sell2 = max(sell, buy + n - fee);
            buy = buy2;
            sell = sell2;
        }
        return sell;
    }
};
```

According to Solution 2, we can merge `buy2` and `sell2` with `buy` and `sell` respectively with no issue. This is because buying and selling on the same day is the same as not trading on day `i`, whose result should be captured already in `buy` and `sell`.