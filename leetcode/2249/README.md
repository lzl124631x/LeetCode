# [2249. Count Lattice Points Inside a Circle (Medium)](https://leetcode.com/problems/count-lattice-points-inside-a-circle)

<p>Given a 2D integer array <code>circles</code> where <code>circles[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code> represents the center <code>(x<sub>i</sub>, y<sub>i</sub>)</code> and radius <code>r<sub>i</sub></code> of the <code>i<sup>th</sup></code> circle drawn on a grid, return <em>the <strong>number of lattice points</strong> </em><em>that are present inside <strong>at least one</strong> circle</em>.</p>
<p><strong>Note:</strong></p>
<ul>
	<li>A <strong>lattice point</strong> is a point with integer coordinates.</li>
	<li>Points that lie <strong>on the circumference of a circle</strong> are also considered to be inside it.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/exa-11.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> circles = [[2,2,1]]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
The figure above shows the given circle.
The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
Hence, the number of lattice points present inside at least one circle is 5.</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/exa-22.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> circles = [[2,2,2],[3,4,1]]
<strong>Output:</strong> 16
<strong>Explanation:</strong>
The figure above shows the given circles.
There are exactly 16 lattice points which are present inside at least one circle. 
Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= circles.length &lt;= 200</code></li>
	<li><code>circles[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
	<li><code>1 &lt;= r<sub>i</sub> &lt;= min(x<sub>i</sub>, y<sub>i</sub>)</code></li>
</ul>

**Companies**:
[Rubrik](https://leetcode.com/company/rubrik)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [Geometry](https://leetcode.com/tag/geometry/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Queries on Number of Points Inside a Circle (Medium)](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-lattice-points-inside-a-circle
// Author: github.com/lzl124631x
// Time: O(N * (X + R) * (Y + R))
// Space: O((X + R) * (Y + R))
class Solution {
    double dist(int a, int b, int x, int y) {
        return sqrt(pow(a - x, 2) + pow(b - y, 2));
    }
public:
    int countLatticePoints(vector<vector<int>>& A) {
        bool seen[201][201] = {};
        int ans = 0;
        for (auto &c : A) {
            int x = c[0], y = c[1], r = c[2];
            for (int a = x - r; a <= x + r; ++a) {
                for (int b = y - r; b <= y + r; ++b) {
                    if (dist(a, b, x, y) <= r && !seen[a][b]) {
                        ++ans;
                        seen[a][b] = true;
                    }
                }
            }
        }
        return ans;
    }
};
```