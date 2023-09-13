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

Let `buy[i+1][k]` be the max balance with `A[0..i]` after exactly `k` buys. `buy[i+1][k]` is initialized with `-Inf`.
Let `sell[i+1][k]` be the max balance with `A[0..i]` after exactly `k` sells. `sell[i+1][k]` is initialized with `0`.

```
buy[i+1][k] = max(
                    buy[i][k],             // skip A[i]
                    sell[i][k-1] - A[i]  // buy A[i]
                )
sell[i+1][k] = max(
                    sell[i][k],           // skip A[i]
                    buy[i][k] + A[i]    // sell A[i]
                )
        where i+1 >= k
```

The answer is `MAX( sell[N][k] )` where `0 <= k <= K`

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(NK)
class Solution {
public:
    int maxProfit(int K, vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<vector<int>> buy(N + 1, vector<int>(K + 1, INT_MIN)), sell(N + 1, vector<int>(K + 1));
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k <= min(i + 1, K); ++k) {
                buy[i + 1][k] = max(buy[i][k], sell[i][k - 1] - A[i]);
                sell[i + 1][k] = max(sell[i][k], buy[i][k] + A[i]);
                ans = max(ans, sell[i + 1][k]);
            }
        }
        return ans;
    }
};
```

## Solution 2. DP Space Optimization

```
buy[i+1][k] = max(
            buy[i][k],           // skip A[i]
            sell[i][k-1] - A[i]  // buy A[i]
        )
sell[i+1][k] = max(
            sell[i][k],           // skip A[i]
            buy[i+1][k] + A[i]    // sell A[i]
                 ^
                 └-- Here changing buy[i][k] to buy[i+1][k] is fine because buying and selling at A[i] is simply no-op.
        )
```

We can see that `buy[i+1][k]` depands on `buy[i][k]` and `sell[i][k-1]`, `sell[i+1][k]` depands on `sell[i][k]` and `buy[i+1][k]`. We can remove the first dimension of `buy` and `sell` arrays, reducing the space complexity from `O(KN)` to `O(K)`.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(K)
class Solution {
public:
    int maxProfit(int K, vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> buy(K + 1, INT_MIN), sell(K + 1);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k <= min(i + 1, K); ++k) {
                buy[k] = max(buy[k], sell[k - 1] - A[i]);
                sell[k] = max(sell[k], buy[k] + A[i]);
                ans = max(ans, sell[k]);
            }
        }
        return ans;
    }
};
```

## Solution 3. Alien Trick

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author: github.com/lzl124631x
// Time: O(Nlog(max(P)))
// Space: O(1)
// Ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/463598/Python-short-O(NlogW)-solution-with-alien-trick
class Solution {
    vector<int> maxProfitWithFee(vector<int> &A, int fee) {  // maxProfit, corresponding number of transactions
        vector<int> best{-A[0], 0}, current{0, 0};
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] + best[0] - fee > current[0]) current = {A[i] + best[0] - fee, 1 + best[1]};
            if (current[0] - A[i] > best[0]) best = {current[0] - A[i], current[1]};
        }
        return current;
    }
public:
    int maxProfit(int k, vector<int>& A) {
        if (A.empty()) return 0;
        int L = 0, R = *max_element(begin(A), end(A));
        return calc(l)[0] + l * k 
        while (L <= R) {
            int M = (L + R) / 2;
            if (maxProfitWithFee(A, M)[1] > k) L = M + 1;
            else R = M - 1;
        }
        return maxProfitWithFee(A, L)[0] + L * k;
    }
};
```