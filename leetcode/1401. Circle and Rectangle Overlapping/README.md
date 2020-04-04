# [1401. Circle and Rectangle Overlapping (Medium)](https://leetcode.com/problems/circle-and-rectangle-overlapping/)

<p>Given a circle represented as (<code>radius</code>, <code>x_center</code>, <code>y_center</code>)&nbsp;and an axis-aligned rectangle represented as (<code>x1</code>, <code>y1</code>, <code>x2</code>, <code>y2</code>),&nbsp;where (<code>x1</code>, <code>y1</code>) are the coordinates of the bottom-left corner, and (<code>x2</code>, <code>y2</code>) are the coordinates of the top-right corner of the&nbsp;rectangle.</p>

<p>Return True if the circle and rectangle are overlapped otherwise return False.</p>

<p>In other words, check if there are <strong>any </strong>point&nbsp;(xi, yi) such that belongs to the circle and the rectangle at the same time.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/20/sample_4_1728.png" style="width: 258px; height: 167px;"></p>

<pre><strong>Input:</strong> radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> Circle and rectangle share the point (1,0) 
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/02/20/sample_2_1728.png" style="width: 150px; height: 135px;"></strong></p>

<pre><strong>Input:</strong> radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/03/03/sample_6_1728.png" style="width: 175px; height: 165px;"></strong></p>

<pre><strong>Input:</strong> radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
<strong>Output:</strong> true
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= radius &lt;= 2000</code></li>
	<li><code>-10^4 &lt;= x_center, y_center, x1, y1, x2, y2 &lt;= 10^4</code></li>
	<li><code>x1 &lt; x2</code></li>
	<li><code>y1 &lt; y2</code></li>
</ul>

**Related Topics**:  
[Geometry](https://leetcode.com/tag/geometry/)

## Solution 1.

Move the center of the circle to the coordinate origin `(0, 0)`, then this problem becomes "is there a point `(x, y)` (`x1 <= x <= x2`, `y1 <= y <= y2`) satisfying `x^2 + y^2 <= r^2`".

So just compute minimum values of `x^2` and `y^2`, then compare the sum with `r^2`..

```cpp
// OJ: https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        x1 -= x_center; x2 -= x_center;
        y1 -= y_center; y2 -= y_center;
        int minX = x1 * x2 > 0 ? min(x1*x1, x2*x2) : 0, minY = y1 * y2 > 0 ? min(y1*y1, y2*y2) : 0;
        return minY + minX <= radius * radius;
    }
};
```