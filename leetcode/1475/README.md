# [1475. Final Prices With a Special Discount in a Shop (Easy)](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/)

<p>Given the array <code>prices</code> where <code>prices[i]</code> is the price of the <code>ith</code> item in a shop. There is a special discount for items in the shop, if you buy the <code>ith</code> item, then you will receive a discount equivalent to <code>prices[j]</code> where <code>j</code> is the <strong>minimum</strong>&nbsp;index such that <code>j &gt; i</code> and <code>prices[j] &lt;= prices[i]</code>, otherwise, you will not receive any discount at all.</p>

<p><em>Return an array where the <code>ith</code> element is the final price you will pay for the <code>ith</code> item of the shop considering the special discount.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> prices = [8,4,6,2,3]
<strong>Output:</strong> [4,2,4,2,3]
<strong>Explanation:</strong>&nbsp;
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.&nbsp;
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.&nbsp;
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.&nbsp;
For items 3 and 4 you will not receive any discount at all.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> prices = [1,2,3,4,5]
<strong>Output:</strong> [1,2,3,4,5]
<strong>Explanation:</strong> In this case, for all items, you will not receive any discount at all.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> prices = [10,1,1,6]
<strong>Output:</strong> [9,0,1,6]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 500</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10^3</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Monotonic Stack

Similar idea as in [496. Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/).

```cpp
// OJ: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> finalPrices(vector<int>& A) {
        stack<int> s;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[s.top()] >= A[i]) {
                A[s.top()] -= A[i];
                s.pop();
            }
            s.push(i);
        }
        return A;
    }
};
```