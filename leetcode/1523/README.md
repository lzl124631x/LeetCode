# [1523. Count Odd Numbers in an Interval Range (Easy)](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)

<p>Given two non-negative integers <code>low</code> and <code><font face="monospace">high</font></code>. Return the <em>count of odd numbers between </em><code>low</code><em> and </em><code><font face="monospace">high</font></code><em>&nbsp;(inclusive)</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> low = 3, high = 7
<strong>Output:</strong> 3
<b>Explanation: </b>The odd numbers between 3 and 7 are [3,5,7].</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> low = 8, high = 10
<strong>Output:</strong> 1
<b>Explanation: </b>The odd numbers between 8 and 10 are [9].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high&nbsp;&lt;= 10^9</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

There are `high - low + 1` numbers in the range, so there are at least `(high - low + 1) / 2` odd numbers. If `low` is odd, then there will be `(high - low + 1 + (low % 2)) / 2` odd numbers.

```cpp
// OJ: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low + 1 + low % 2) / 2;
    }
};
```