# [963. Minimum Area Rectangle II (Medium)](https://leetcode.com/problems/minimum-area-rectangle-ii/)

<p>Given a set of points in the xy-plane, determine the minimum area of <strong>any</strong> rectangle formed from these points, with sides <strong>not necessarily parallel</strong> to the x and y axes.</p>

<p>If there isn't any rectangle, return 0.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/21/1a.png" style="width: 150px; height: 151px;"></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[1,2],[2,1],[1,0],[0,1]]</span>
<strong>Output: </strong><span id="example-output-1">2.00000
<strong>Explanation:</strong> </span><span>The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/22/2.png" style="width: 150px; height: 94px;"></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[0,1],[2,1],[1,1],[1,0],[2,0]]</span>
<strong>Output: </strong><span id="example-output-2">1.00000
</span><strong>Explanation:</strong> The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/22/3.png" style="width: 160px; height: 167px;"></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[[0,3],[1,2],[3,1],[1,3],[2,1]]</span>
<strong>Output: </strong><span id="example-output-3">0
</span><span><strong>Explanation:</strong> There is no possible rectangle to form from these points.</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/21/4c.png" style="width: 160px; height: 155px;"></p>

<pre><strong>Input: </strong><span id="example-input-4-1">[[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]</span>
<strong>Output: </strong><span id="example-output-4">2.00000
</span><span><strong>Explanation:</strong> The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.</span>
</pre>
</div>

<p>&nbsp;</p>
</div>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= points.length &lt;= 50</code></li>
	<li><code>0 &lt;=&nbsp;points[i][0] &lt;=&nbsp;40000</code></li>
	<li><code>0 &lt;=&nbsp;points[i][1] &lt;=&nbsp;40000</code></li>
	<li>All points are distinct.</li>
	<li>Answers within <code>10^-5</code> of the actual value will be accepted as correct.</li>
</ol>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Geometry](https://leetcode.com/tag/geometry/)

## Solution 1.

### Intuition

For each triangle, let's try to find the 4th point and whether it is a rectangle.

### Algorithm

Say the first 3 points are `p1, p2, p3`, and that `p2` and `p3` are opposite corners of the final rectangle. The 4th point must be `p4 = p2 + p3 - p1` (using vector notation) because `p1, p2, p4, p3` must form a parallelogram, and `p1 + (p2 - p1) + (p3 - p1) = p4`.

If this point exists in our collection (we can use a set to check), then we should check that the angles of this parallelogram are 90 degrees. The easiest way is to check the dot product of the two vectors `(p2 - p1)` and `(p3 - p1)`. (Another way is that we could normalize the vectors to length 1, and check that one equals the other rotated by 90 degrees.)

```cpp
// OJ: https://leetcode.com/problems/minimum-area-rectangle-ii/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-area-rectangle-ii/solution/
class Solution {
    double dist(vector<int> &a, vector<int> &b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
public:
    double minAreaFreeRect(vector<vector<int>>& A) {
        int N = A.size();
        set<vector<int>> s(begin(A), end(A));
        double ans = DBL_MAX;
        for (int i = 0; i < N; ++i) {
            auto &p1 = A[i];
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                auto &p2 = A[j];
                for (int k = j + 1; k < N; ++k) {
                    if (k == i) continue;
                    auto &p3 = A[k], p4 = vector<int>{ p2[0] + p3[0] - p1[0], p2[1] + p3[1] - p1[1] };
                    if (s.count(p4)) {
                        int dot = (p2[0] - p1[0]) * (p3[0] - p1[0]) + (p2[1] - p1[1]) * (p3[1] - p1[1]);
                        if (dot == 0) {
                            double area = dist(p1, p2) * dist(p1, p3);
                            ans = min(ans, area);
                        }
                    }
                }
            }
        }
        return ans == DBL_MAX ? 0 : ans;
    }
};
```

## Solution 2. Map

1. Two diagonals of a rectangle bisect each other, and are of equal length.
1. A map's key is a string including diagonal length and coordinate of the diagonal center; A map's value is a vector of index pairs of two points forming the diagonal.

The first part takes `O(N^2)` time.

For the second part, according to the Theorem 9 in [Finding squares and rectangles in sets of points. M.J. van Kreveld and M.T. de Berg](http://www.cs.uu.nl/research/techreps/repo/CS-1989/1989-10.pdf), there are at most `O(N^2 * sqrt(N))` rectangles with these `N` points, so the time complexity is `O(N^2 * sqrt(N))`.

```cpp
// OJ: https://leetcode.com/problems/minimum-area-rectangle-ii/
// Author: github.com/lzl124631x
// Time: O(N^2 * sqrt(N))
// Space: O(N^2)
// Ref: https://leetcode.com/problems/minimum-area-rectangle-ii/discuss/208361/JAVA-O(n2)-using-Map
class Solution {
    inline long distance(vector<int> &a, vector<int> &b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
public:
    double minAreaFreeRect(vector<vector<int>>& A) {
        int N = A.size();
        double ans = DBL_MAX;
        if (N < 4) return 0;
        unordered_map<string, vector<vector<int>>> m;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                long dist = distance(A[i], A[j]);
                double centerX = (A[i][0] + A[j][0]) / 2.0;
                double centerY = (A[i][1] + A[j][1]) / 2.0;
                auto key = to_string(dist) + "," + to_string(centerX) + "," + to_string(centerY);
                m[key].push_back({ i, j });
            }
        }
        for (auto &[key, val] : m) {
            if (val.size() <= 1) continue;
            for (int i = 0; i < val.size(); ++i) {
                for (int j = i + 1; j < val.size(); ++j) {
                    int a = val[i][0], b = val[i][1], c = val[j][0];
                    double len1 = sqrt(distance(A[a], A[c]));
                    double len2 = sqrt(distance(A[b], A[c]));
                    ans = min(ans, len1 * len2);
                }
            }
        }
        return ans == DBL_MAX ? 0 : ans;
    }
};
```