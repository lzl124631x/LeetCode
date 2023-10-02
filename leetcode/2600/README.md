# [2600. K Items With the Maximum Sum (Easy)](https://leetcode.com/problems/k-items-with-the-maximum-sum)

<p>There is a bag that consists of items, each item&nbsp;has a number <code>1</code>, <code>0</code>, or <code>-1</code> written on it.</p>
<p>You are given four <strong>non-negative </strong>integers <code>numOnes</code>, <code>numZeros</code>, <code>numNegOnes</code>, and <code>k</code>.</p>
<p>The bag initially contains:</p>
<ul>
	<li><code>numOnes</code> items with <code>1</code>s written on them.</li>
	<li><code>numZeroes</code> items with <code>0</code>s written on them.</li>
	<li><code>numNegOnes</code> items with <code>-1</code>s written on them.</li>
</ul>
<p>We want to pick exactly <code>k</code> items among the available items. Return <em>the <strong>maximum</strong> possible sum of numbers written on the items</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 2 items with 1 written on them and get a sum in a total of 2.
It can be proven that 2 is the maximum possible sum.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong> We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 3 items with 1 written on them, and 1 item with 0 written on it, and get a sum in a total of 3.
It can be proven that 3 is the maximum possible sum.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>0 &lt;= numOnes, numZeros, numNegOnes &lt;= 50</code></li>
	<li><code>0 &lt;= k &lt;= numOnes + numZeros + numNegOnes</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Maximum Subarray (Medium)](https://leetcode.com/problems/maximum-subarray/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/k-items-with-the-maximum-sum
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) return k;
        k -= numOnes;
        if (k <= numZeros) return numOnes;
        k -= numZeros;
        return numOnes - min(k, numNegOnes);
    }
};
```