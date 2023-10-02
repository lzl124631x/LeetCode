# [2481. Minimum Cuts to Divide a Circle (Easy)](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle)

<p>A <strong>valid cut</strong> in a circle can be:</p>
<ul>
	<li>A cut that is represented by a straight line that touches two points on the edge of the circle and passes through its center, or</li>
	<li>A cut that is represented by a straight line that touches one point on the edge of the circle and its center.</li>
</ul>
<p>Some valid and invalid cuts are shown in the figures below.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/29/alldrawio.png" style="width: 450px; height: 174px;">
<p>Given the integer <code>n</code>, return <em>the <strong>minimum</strong> number of cuts needed to divide a circle into </em><code>n</code><em> equal slices</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/24/11drawio.png" style="width: 200px; height: 200px;">
<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The above figure shows how cutting the circle twice through the middle divides it into 4 equal slices.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/24/22drawio.png" style="width: 200px; height: 201px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong>
At least 3 cuts are needed to divide the circle into 3 equal slices. 
It can be shown that less than 3 cuts cannot result in 3 slices of equal size and shape.
Also note that the first cut will not divide the circle into distinct parts.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>

**Companies**:
[tcs](https://leetcode.com/company/tcs)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Geometry](https://leetcode.com/tag/geometry/)

**Similar Questions**:
* [Smallest Even Multiple (Easy)](https://leetcode.com/problems/smallest-even-multiple/)
* [Count Total Number of Colored Cells (Medium)](https://leetcode.com/problems/count-total-number-of-colored-cells/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-cuts-to-divide-a-circle
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int numberOfCuts(int n) {
        return n == 1 ? 0 : (n % 2 ? n : n / 2);
    }
};
```