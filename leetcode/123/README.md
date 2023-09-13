# [123. Best Time to Buy and Sell Stock III (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

<p>Say you have an array for which the <em>i</em><sup>th</sup> element is the price of a given stock on day <em>i</em>.</p>

<p>Design an algorithm to find the maximum profit. You may complete at most <em>two</em> transactions.</p>

<p><strong>Note:&nbsp;</strong>You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [3,3,5,0,0,3,1,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
&nbsp;            Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [1,2,3,4,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
&nbsp;            Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
&nbsp;            engaging multiple transactions at the same time. You must sell before buying again.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> [7,6,4,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this case, no transaction is done, i.e. max profit = 0.</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Best Time to Buy and Sell Stock II (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
* [Best Time to Buy and Sell Stock IV (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
* [Maximum Sum of 3 Non-Overlapping Subarrays (Hard)](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)

## Solution 1. DP

Reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution

Let `dp[k][i]` be the maximum profit using at most `k` transactions, on `i`-th day.

If we don't trade on `i`-th day, `dp[k][i] = dp[k][i - 1]`

Otherwise, there must be some `j`-th day (`j` is in range `[0, i-1]`) that we maximize our profit by buying on `j`-th day and sell on `i`-th day. So `dp[k][i] = max(dp[k-1][j-1] + prices[i] - prices[j] | 0 <= j < i)`.

Since `prices[i]` is a constant given `i`, we can make it `dp[k][i] = prices[i] + max(dp[k-1][j-1] - prices[j] | 0 <= j < i`)

```
dp[k][i] = max(
                dp[k][i - 1],
                prices[i] + max( dp[k - 1][j - 1] - prices[j] | 0 <= j < i )
              )
           where i >= 1

dp[i][0] = dp[0][i] = 0
```

So we can use the following solution. But it will get TLE.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN^2)
// Space: O(KN)
// NOTE: this will get TLE
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(3, vector<int>(N + 1));
        for (int k = 1; k < 3; ++k) {
            for (int i = 1; i < N; ++i) {
                int maxVal = INT_MIN;
                for (int j = 0; j < i; ++j) maxVal = max(maxVal, dp[k - 1][j] - A[j]);
                dp[k][i + 1] = max(dp[k][i], A[i] + maxVal);
            }
        }
        return dp[2][N];
    }
};
```

We can optimize the `maxVal` part by not repetitively computing the `maxVal`.

Let `m[k][i] = max( dp[k - 1][j - 1] - prices[j] | 0 <= j < i )`.

```
m[k][i] = max(
               - prices[0],
    dp[k-1][0] - prices[1],
    dp[k-1][1] - prices[2],
    ...
    dp[k-1][i-2] - prices[i-1]
)
```

We have `m[k][i] = max(m[k][i - 1], dp[k - 1][i - 2] - prices[i - 1])` where `i >= 1`.

So:

```
dp[k][i] = max(dp[k][i - 1], prices[i] + m[k][i])

where m[k][i] = max(m[k][i - 1], dp[k - 1][i - 2] - A[i - 1])
    and i >= 1

dp[i][0] = dp[0][i] = 0
```

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(3, vector<int>(N + 1));
        for (int k = 1; k < 3; ++k) {
            int maxVal = INT_MIN;
            for (int i = 1; i < N; ++i) {
                maxVal = max(maxVal, dp[k - 1][i - 1] - A[i - 1]);
                dp[k][i + 1] = max(dp[k][i], A[i] + maxVal);
            }
        }
        return dp[2][N];
    }
};
```

The following change is totally optional which just simplify the code a tiny bit.

In equation `dp[k][i] = prices[i] + max(dp[k-1][j-1] - prices[j] | 0 <= j < i)`, we can also add the `j == i` case to the `0 <= j < i`, so that it becomes:

```
dp[k][i] = prices[i] + max(dp[k-1][j-1] - prices[j] | 0 <= j <= i)
```

This works because buying and selling at the same `i`-th day is effectively the same as not trading at `i`-th day.

Let `m[k][i] = max( dp[k - 1][j - 1] - prices[j] | 0 <= j <= i )`.

We have `m[k][i] = max(m[k][i - 1], dp[k - 1][i - 1] - prices[i])` where `i >= 0` and `m[k][-1] == -INF`.

So:

```
dp[k][i] = max(dp[k][i - 1], prices[i] + m[k][i])

where m[k][i] = max(m[k][i - 1], dp[k - 1][i - 1] - A[i])
    and i >= 0

m[k][-1] = -INF
dp[i][0] = dp[0][i] = 0
```

For each `k`, we can store `m[k][i]` in a single variable `maxVal` using the relationship `m[k][i] = max(m[k][i - 1], dp[k - 1][i - 1] - prices[i])`.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(3, vector<int>(N + 1));
        for (int k = 1; k < 3; ++k) {
            int maxVal = INT_MIN;
            for (int i = 0; i < N; ++i) {
                maxVal = max(maxVal, dp[k - 1][i] - A[i]);
                dp[k][i + 1] = max(dp[k][i], A[i] + maxVal);
            }
        }
        return dp[2][N];
    }
};
```

## Solution 2. DP Space Optimization

In this formula 

```
dp[k][i] = max(dp[k][i - 1], prices[i] + m[k][i])

where m[k][i] = max(m[k][i - 1], dp[k - 1][i - 1] - A[i])
    and i >= 0

m[k][-1] = -INF
dp[i][0] = dp[0][i] = 0
```

`dp[k][i]` is dependent on `dp[k][i-1]` and `dp[k-1][i-1]`.

If we flip `k` and `i`, we have:

```
dp[i][k] = max(dp[i - 1][k], prices[i] + m[i][k])

where m[i][k] = max(m[i - 1][k], dp[i - 1][k - 1] - A[i])
    and i >= 0

m[-1][k] = -INF
dp[i][0] = dp[0][i] = 0
```

Be cautious that, unlike that we can save `m[k][i]` using a single variable previously, we need to save the `m[i][k]` for each `k`.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(3));
        vector<int> maxVal(3, INT_MIN);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k < 3; ++k) {
                maxVal[k] = max(maxVal[k], dp[i][k - 1] - A[i]);
                dp[i + 1][k] = max(dp[i][k], A[i] + maxVal[k]);
            }
        }
        return dp[N][2];
    }
};
```

Now, `dp[i][k]` is dependent on `dp[i-1][k]` and `m[i][k]`. And because `m[i][k]` is dependent on `dp[i-1][k-1]`, it **seems like** `dp[i][k]` is dependent on `dp[i-1][k-1]` as well, we must loop backwards from `k` to `1`.

```
// This dependency can actually be loosen considering `m[i][k]` is stored separatly

dp[i-1][k-1]      dp[i-1][k]

              \        |
              
                  dp[i][k]
```

Nevertheless, we can use an array of length `2 * K` to solve it.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(K)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(2, vector<int>(3));
        vector<int> maxVal(3, INT_MIN);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k < 3; ++k) {
                maxVal[k] = max(maxVal[k], dp[i % 2][k - 1] - A[i]);
                dp[(i + 1) % 2][k] = max(dp[i % 2][k], A[i] + maxVal[k]);
            }
        }
        return dp[N % 2][2];
    }
};
```

But because `m[i][k]` is stored separately, `dp[i][k]` is actually not dependent on `dp[i-1][k-1]`.

```

dp[i-1][k]

     |
             
  dp[i][k]
```

and

```
dp[i-1][k-1]

    |

  m[i][k]
```

So `dp[i][k]` is only dependent on the `dp[i-1][k]` which is in the previous row! We don't have to loop `k` from `K` to `1`, we can do it **in either direction**.

Now we can optimize the space complexity of the DP array from `O(NK)` to `O(K)`.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(K)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<int> dp(3);
        vector<int> maxVal(3, INT_MIN);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k < 3; ++k) {
                maxVal[k] = max(maxVal[k], dp[k - 1] - A[i]);
                dp[k] = max(dp[k], A[i] + maxVal[k]);
            }
        }
        return dp[2];
    }
};
```

## Solution 3. DP for K = 2

Since in this problem `k = 2`, we can simply use 4 variables to store the `dp` and `maxVal`.

Consider `m[i][k] = max( dp[j - 1][k - 1] - prices[j] | 0 <= j <= i )`.

```
m[i][k] = max(
               - prices[0],
    dp[0][k-1] - prices[1],
    dp[1][k-1] - prices[2],
    ...
    dp[i-1][k-1] - prices[i]
)
```

`dp[i-1][k-1]` is the max profit we can get with at most `k-1` transactions at `i-1`-th day. And we can regard the `-prices[i]` part as "trying to buy at `i`-th day" which adds `-prices[i]` to my profit.

So we can regard `m[i][k]` as "the max profit if we buy at `i`-th day using at most `k` tractions" where the last `k`-th transaction contains only buying.

Thus, we can name `m[i][k]` as `buy[i][k]` and name `dp[i][k]` as `sell[i][k]`, i.e. the max profit if we buy/sell at `i`-th day using `k` transactions.

Since `k = 2`, we just need 4 variables.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/5934/is-it-best-solution-with-o-n-o-1
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    for (int p : prices) {
        buy1 = max(buy1, -p);
        sell1 = max(sell1, buy1 + p);
        buy2 = max(buy2, sell1 - p);
        sell2 = max(sell2, buy2 + p);
    }
    return sell2;
  }
};
```