# [1515. Best Position for a Service Centre (Hard)](https://leetcode.com/problems/best-position-for-a-service-centre/)

<p>A delivery company wants to build a new service centre in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new centre in a position such that <strong>the sum of the euclidean distances to all customers is minimum</strong>.</p>

<p>Given an array <code>positions</code> where <code>positions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> is the position of the <code>ith</code> customer on the map, return <em>the minimum sum of the euclidean distances</em> to all customers.</p>

<p>In other words, you need to choose the position of the service centre <code>[x<sub>centre</sub>, y<sub>centre</sub>]</code> such that the following formula is minimized:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_edited.jpg">
<p>Answers within&nbsp;<code>10^-5</code>&nbsp;of the actual value will be accepted.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_e1.jpg" style="width: 377px; height: 362px;">
<pre><strong>Input:</strong> positions = [[0,1],[1,0],[1,2],[2,1]]
<strong>Output:</strong> 4.00000
<strong>Explanation:</strong> As shown, you can see that choosing [x<sub>centre</sub>, y<sub>centre</sub>] = [1, 1] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/25/q4_e3.jpg" style="width: 419px; height: 419px;">
<pre><strong>Input:</strong> positions = [[1,1],[3,3]]
<strong>Output:</strong> 2.82843
<strong>Explanation:</strong> The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> positions = [[1,1]]
<strong>Output:</strong> 0.00000
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> positions = [[1,1],[0,0],[2,0]]
<strong>Output:</strong> 2.73205
<strong>Explanation:</strong> At the first glance, you may think that locating the centre at [1, 0] will achieve the minimum sum, but locating it at [1, 0] will make the sum of distances = 3.
Try to locate the centre at [1.0, 0.5773502711] you will see that the sum of distances is 2.73205.
Be careful with the precision!
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> positions = [[0,1],[3,2],[4,5],[7,6],[8,9],[11,1],[2,12]]
<strong>Output:</strong> 32.94036
<strong>Explanation:</strong> You can use [4.3460852395, 4.9813795505] as the position of the centre.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;positions.length &lt;= 50</code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;=&nbsp;positions[i][0],&nbsp;positions[i][1] &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Geometry](https://leetcode.com/tag/geometry/)

## Solution 1. Simulated Annealing

Starting from a random point (here I use `(0, 0)`). We move around in 4 directions with some initial `step` (I used `100`).

If we can find smaller total distance, we move to that point.

Otherwise, we set `step /= 2`.

We keep this iteration until the `step` is smaller than `1e-6`.

See more:
* https://stackoverflow.com/questions/12934213/how-to-find-out-geometric-median
* https://en.wikipedia.org/wiki/Geometric_median

```cpp
// OJ: https://leetcode.com/problems/best-position-for-a-service-centre/
// Author: github.com/lzl124631x
// Time: O(N * S) where S is the steps taken to reach the center
// Space: O(1)
class Solution {
    double dist(vector<int> &a, vector<double> &b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
    double all(vector<vector<int>> &A, vector<double> &p) {
        double ans = 0;
        for (auto &a : A) ans += dist(a, p);
        return ans;
    }
    const int dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
public:
    double getMinDistSum(vector<vector<int>>& A) {
        double ans = DBL_MAX, step = 100, eps = 1e-6;
        vector<double> p(2, 0);
        while (step > eps) {
            bool found = false;
            for (auto &dir : dirs) {
                vector<double> next = {p[0] + step * dir[0], p[1] + step * dir[1]};
                double d = all(A, next);
                if (d < ans) {
                    ans = d;
                    p = next;
                    found = true;
                    break;
                }
            }
            if (!found) step /= 2;
        }
        return ans;
    }
};
```

## Other Solutions

* https://leetcode.com/problems/best-position-for-a-service-centre/discuss/731577/C%2B%2B-with-picture-zoom-in