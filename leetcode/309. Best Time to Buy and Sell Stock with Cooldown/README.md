# [309. Best Time to Buy and Sell Stock with Cooldown (Medium)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

<p>Say you have an array for which the <i>i</i><sup>th</sup> element is the price of a given stock on day <i>i</i>.</p>

<p>Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:</p>

<ul>
	<li>You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).</li>
	<li>After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)</li>
</ul>

<p><b>Example:</b></p>

<pre><strong>Input:</strong> [1,2,3,0,2]
<strong>Output: </strong>3 
<strong>Explanation:</strong> transactions = [buy, sell, cooldown, buy, sell]
</pre>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Best Time to Buy and Sell Stock II (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Solution 1. DP

See my notes for [123. Best Time to Buy and Sell Stock III (Hard)](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III) and [188. Best Time to Buy and Sell Stock IV (Hard)](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/188.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20IV) as some reference.

Let `dp[i]` be the max profit at `i`-th day.

If we don't trade on `i`-day, then `dp[i] = dp[i-1]`.

Otherwise, we buy on `j`-th day (`j` is in `[0, i]`) and we sell on `i`-day, `dp[i] = max(prices[i] - prices[j] + dp[j - 2])`.

So in sum:

```
dp[i] = max(
    dp[i-1],
    prices[i] + max(dp[j-2] - prices[j] | 0 <= j <= i)
)
```

We can define `buy[i] = max(dp[j-2] - prices[j] | 0 <= j <= i)` and we can get `buy[i]` using `buy[i-1]`:

```
buy[i] = max(buy[i-1], dp[i-2] - prices[i])  where i >= 0
buy[-1] = -INF
```

In this way we save the computation to get `buy[i]`.

```
dp[i] = max(
    dp[i-1],
    prices[i] + buy[i]
)
buy[i] = max(buy[i-1], dp[i-2] - prices[i])  where i >= 0
buy[-1] = -INF
```

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            buy = max(buy, (i >= 1 ? dp[i - 1] : 0) - A[i]);
            dp[i + 1] = max(dp[i], buy + A[i]);
        }
        return dp[N];
    }
};
```

## Solution 2. DP Space Optimization

Since `dp[i]` is only dependent on `dp[i-1]` and `dp[i-2]`, we can reduce the size of the `dp` array from `N` to `3`.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN;
        vector<int> dp(3);
        for (int i = 0; i < N; ++i) {
            buy = max(buy, (i - 1 >= 0 ? dp[(i - 1) % 3] : 0) - A[i]);
            dp[(i + 1) % 3] = max(dp[i % 3], buy + A[i]);
        }
        return dp[N % 3];
    }
};
```