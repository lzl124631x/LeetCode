# [223. Rectangle Area (Medium)](https://leetcode.com/problems/rectangle-area)

<p>Given the coordinates of two <strong>rectilinear</strong> rectangles in a 2D plane, return <em>the total area covered by the two rectangles</em>.</p>

<p>The first rectangle is defined by its <strong>bottom-left</strong> corner <code>(ax1, ay1)</code> and its <strong>top-right</strong> corner <code>(ax2, ay2)</code>.</p>

<p>The second rectangle is defined by its <strong>bottom-left</strong> corner <code>(bx1, by1)</code> and its <strong>top-right</strong> corner <code>(bx2, by2)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="Rectangle Area" src="https://assets.leetcode.com/uploads/2021/05/08/rectangle-plane.png" style="width: 700px; height: 365px;" />
<pre>
<strong>Input:</strong> ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
<strong>Output:</strong> 45
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>4</sup> &lt;= ax1 &lt;= ax2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= ay1 &lt;= ay2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= bx1 &lt;= bx2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= by1 &lt;= by2 &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Facebook](https://leetcode.com/company/facebook), [Zillow](https://leetcode.com/company/zillow)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [Geometry](https://leetcode.com/tag/geometry)

**Similar Questions**:
* [Rectangle Overlap (Easy)](https://leetcode.com/problems/rectangle-overlap)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rectangle-area
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if (ax1 > bx1) swap(ax1, bx1), swap(ay1, by1), swap(ax2, bx2), swap(ay2, by2);
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - max(0, min(ax2, bx2) - bx1) * max(0, min(ay2, by2) - max(ay1, by1));
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/rectangle-area
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    int area(int a, int b, int c, int d) {
        return (c > a ? c - a : 0) * (d > b ? d - b : 0);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = max(A, E), b = max(B, F), c = min(C, G), d = min(D, H);
        return area(A, B, C, D) + area(E, F, G, H) - area(a, b, c, d);
    }
};
```