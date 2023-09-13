# [1453. Maximum Number of Darts Inside of a Circular Dartboard (Hard)](https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/)

<p>You have a very large square wall and a circular dartboard placed on the wall.&nbsp;You have been challenged to throw darts into the board blindfolded.&nbsp;Darts thrown at the wall are represented as an array of&nbsp;<code>points</code> on a 2D plane.&nbsp;</p>

<p>Return&nbsp;the maximum number of points that are within or&nbsp;lie&nbsp;on&nbsp;<strong>any</strong> circular dartboard of radius&nbsp;<code>r</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/04/29/sample_1_1806.png" style="width: 186px; height: 159px;"></p>

<pre><strong>Input:</strong> points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> Circle dartboard with center in (0,0) and radius = 2 contain all points.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/29/sample_2_1806.png" style="width: 224px; height: 183px;"></strong></p>

<pre><strong>Input:</strong> points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
<strong>Output:</strong> 5
<strong>Explanation:</strong> Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 100</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10^4 &lt;= points[i][0], points[i][1] &lt;= 10^4</code></li>
	<li><code>1 &lt;= r &lt;= 5000</code></li>
</ul>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Geometry](https://leetcode.com/tag/geometry/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(1)
class Solution {
    inline double dist(const vector<double> &a, const vector<double> &b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
    vector<double> getPoint(const vector<double> &a, const vector<double> &b, double p, double q) {
        double x = (a[1] - b[1] + b[0] * q - a[0] * p) / (q - p);
        double y = a[1] + p * (x - a[0]);
        return {x, y};
    }
    vector<vector<double>> getCenters(const vector<double> &a, const vector<double> &b, int r) {
        double d = dist(a, b);
        if (d > 2 * r) return {};
        if (d == 2 * r) return {{ (a[0] + b[0]) / 2, (a[1] + b[1]) / 2 }};
        double theta = acos(d / 2 / r);
        double alpha = atan2(a[1] - b[1], a[0] - b[0]);
        double p = tan(alpha + theta), q = tan(alpha - theta);
        return { getPoint(a, b, p, q), getPoint(a, b, q, p) };
    }
public:
    int numPoints(vector<vector<int>>& A, int r) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (auto &center : getCenters({(double)A[i][0], (double)A[i][1]}, {(double)A[j][0], (double)A[j][1]}, r)) {
                    int cnt = 0;
                    for (auto &p : A) {
                        cnt += dist(center, {(double)p[0], (double)p[1]}) <= r + 0.00001;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
```


## TODO

https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/636372/JavaC%2B%2BPython-POJ-1981