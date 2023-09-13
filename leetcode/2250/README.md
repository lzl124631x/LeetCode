# [2250. Count Number of Rectangles Containing Each Point (Medium)](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point)

<p>You are given a 2D integer array <code>rectangles</code> where <code>rectangles[i] = [l<sub>i</sub>, h<sub>i</sub>]</code> indicates that <code>i<sup>th</sup></code> rectangle has a length of <code>l<sub>i</sub></code> and a height of <code>h<sub>i</sub></code>. You are also given a 2D integer array <code>points</code> where <code>points[j] = [x<sub>j</sub>, y<sub>j</sub>]</code> is a point with coordinates <code>(x<sub>j</sub>, y<sub>j</sub>)</code>.</p>
<p>The <code>i<sup>th</sup></code> rectangle has its <strong>bottom-left corner</strong> point at the coordinates <code>(0, 0)</code> and its <strong>top-right corner</strong> point at <code>(l<sub>i</sub>, h<sub>i</sub>)</code>.</p>
<p>Return<em> an integer array </em><code>count</code><em> of length </em><code>points.length</code><em> where </em><code>count[j]</code><em> is the number of rectangles that <strong>contain</strong> the </em><code>j<sup>th</sup></code><em> point.</em></p>
<p>The <code>i<sup>th</sup></code> rectangle <strong>contains</strong> the <code>j<sup>th</sup></code> point if <code>0 &lt;= x<sub>j</sub> &lt;= l<sub>i</sub></code> and <code>0 &lt;= y<sub>j</sub> &lt;= h<sub>i</sub></code>. Note that points that lie on the <strong>edges</strong> of a rectangle are also considered to be contained by that rectangle.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/example1.png" style="width: 300px; height: 509px;">
<pre><strong>Input:</strong> rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
<strong>Output:</strong> [2,1]
<strong>Explanation:</strong> 
The first rectangle contains no points.
The second rectangle contains only the point (2, 1).
The third rectangle contains the points (2, 1) and (1, 4).
The number of rectangles that contain the point (2, 1) is 2.
The number of rectangles that contain the point (1, 4) is 1.
Therefore, we return [2, 1].
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/example2.png" style="width: 300px; height: 312px;">
<pre><strong>Input:</strong> rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
<strong>Output:</strong> [1,3]
<strong>Explanation:
</strong>The first rectangle contains only the point (1, 1).
The second rectangle contains only the point (1, 1).
The third rectangle contains the points (1, 3) and (1, 1).
The number of rectangles that contain the point (1, 3) is 1.
The number of rectangles that contain the point (1, 1) is 3.
Therefore, we return [1, 3].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= rectangles.length, points.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>rectangles[i].length == points[j].length == 2</code></li>
	<li><code>1 &lt;= l<sub>i</sub>, x<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= h<sub>i</sub>, y<sub>j</sub> &lt;= 100</code></li>
	<li>All the <code>rectangles</code> are <strong>unique</strong>.</li>
	<li>All the <code>points</code> are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Queries on Number of Points Inside a Circle (Medium)](https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-rectangles-containing-each-point
// Author: github.com/lzl124631x
// Time: O(R + PlogR)
// Space: O(R)
// Ref: https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/solutions/1976969
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& R, vector<vector<int>>& P) {
        vector<int> m[101]; // height -> lengths
        for (auto &r : R) m[r[1]].push_back(r[0]);
        for (auto &lens : m) sort(begin(lens), end(lens));
        vector<int> ans;
        for (auto &p : P) {
            int x = p[0], y = p[1], cnt = 0;
            for (int j = y; j <= 100; ++j) {
                cnt += end(m[j]) - lower_bound(begin(m[j]), end(m[j]), x);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```