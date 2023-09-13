# [1833. Maximum Ice Cream Bars (Medium)](https://leetcode.com/problems/maximum-ice-cream-bars/)

<p>It is a sweltering summer day, and a boy wants to buy some ice cream bars.</p>

<p>At the store, there are <code>n</code> ice cream bars. You are given an array <code>costs</code> of length <code>n</code>, where <code>costs[i]</code> is the price of the <code>i<sup>th</sup></code> ice cream bar in coins. The boy initially has <code>coins</code> coins to spend, and he wants to buy as many ice cream bars as possible.&nbsp;</p>

<p>Return <em>the <strong>maximum</strong> number of ice cream bars the boy can buy with </em><code>coins</code><em> coins.</em></p>

<p><strong>Note:</strong> The boy can buy the ice cream bars in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> costs = [1,3,2,4,1], coins = 7
<strong>Output:</strong> 4
<strong>Explanation: </strong>The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> costs = [10,6,8,7,7,8], coins = 5
<strong>Output:</strong> 0
<strong>Explanation: </strong>The boy cannot afford any of the ice cream bars.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> costs = [1,6,3,1,2,5], coins = 20
<strong>Output:</strong> 6
<strong>Explanation: </strong>The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>costs.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= costs[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins &lt;= 10<sup>8</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. Greedy

Greedily take the cheapest ice cream first.

```cpp
// OJ: https://leetcode.com/problems/maximum-ice-cream-bars/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxIceCream(vector<int>& A, int B) {
        sort(begin(A), end(A));
        int ans = 0;
        for (int n : A) {
            if (B < n) break;
            ++ans;
            B -= n;
        }
        return ans;
    }
};
```