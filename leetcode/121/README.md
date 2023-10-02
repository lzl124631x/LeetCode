# [121. Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

<p>Say you have an array for which the <em>i</em><sup>th</sup> element is the price of a given stock on day <em>i</em>.</p>

<p>If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.</p>

<p>Note that you cannot sell a stock before you buy one.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [7,1,5,3,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
&nbsp;            Not 7-1 = 6, as selling price needs to be larger than buying price.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [7,6,4,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this case, no transaction is done, i.e. max profit = 0.
</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [DoorDash](https://leetcode.com/company/doordash), [Adobe](https://leetcode.com/company/adobe), [Morgan Stanley](https://leetcode.com/company/morgan-stanley), [Citadel](https://leetcode.com/company/citadel), [Walmart Labs](https://leetcode.com/company/walmart-labs), [VMware](https://leetcode.com/company/vmware), [Redfin](https://leetcode.com/company/redfin)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, ans = 0;
        for (int p : prices) {
            minVal = min(minVal, p);
            ans = max(ans, p - minVal);
        }
        return ans;
    }
};
```

```js
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
var maxProfit = function(A) {
    let min = Infinity, ans = 0;
    for (let i = 0; i < A.length; ++i) {
        min = Math.min(min, A[i]);
        ans = Math.max(ans, A[i] - min);
    }
    return ans;
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        int buy = INT_MIN, sell = 0;
        for (int n : A) {
            buy = max(buy, -n);
            sell = max(sell, buy + n);
        }
        return sell;
    }
};
```