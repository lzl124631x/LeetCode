# [1344. Angle Between Hands of a Clock (Medium)](https://leetcode.com/problems/angle-between-hands-of-a-clock/)

<p>Given two numbers, <code>hour</code> and <code>minutes</code>. Return the smaller angle (in sexagesimal units) formed between the <code>hour</code> and the <code>minute</code> hand.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/12/26/sample_1_1673.png" style="width: 230px; height: 225px;"></p>

<pre><strong>Input:</strong> hour = 12, minutes = 30
<strong>Output:</strong> 165
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/12/26/sample_2_1673.png" style="width: 230px; height: 225px;"></p>

<pre><strong>Input:</strong> hour = 3, minutes = 30
<strong>Output:</strong> 75
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/12/26/sample_3_1673.png" style="width: 230px; height: 225px;"></strong></p>

<pre><strong>Input:</strong> hour = 3, minutes = 15
<strong>Output:</strong> 7.5
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> hour = 4, minutes = 50
<strong>Output:</strong> 155
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> hour = 12, minutes = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= hour &lt;= 12</code></li>
	<li><code>0 &lt;= minutes &lt;= 59</code></li>
	<li>Answers within&nbsp;<code>10^-5</code>&nbsp;of the actual value will be accepted as correct.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    double angleClock(int h, int m) {
        double a = h * 30 + m * 0.5, b = m * 6, d = abs(a - b);
        return min(d, 360 - d);
    }
};
```