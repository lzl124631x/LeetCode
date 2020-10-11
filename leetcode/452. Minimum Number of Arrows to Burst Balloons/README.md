# [452. Minimum Number of Arrows to Burst Balloons (Medium)](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)

<p>There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.</p>

<p>An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with <code>x<sub>start</sub></code> and <code>x<sub>end</sub></code> bursts by an arrow shot at <code>x</code> if <code>x<sub>start</sub> ≤ x ≤ x<sub>end</sub></code>. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.</p>

<p>Given an array <code>points</code> where <code>points[i] = [x<sub>start</sub>, x<sub>end</sub>]</code>, return&nbsp;<em>the minimum number of arrows that must be shot to burst all balloons</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> points = [[10,16],[2,8],[1,6],[7,12]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[1,2],[3,4],[5,6],[7,8]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> points = [[1,2],[2,3],[3,4],[4,5]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> points = [[1,2]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> points = [[2,3],[2,3]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>points.length == 2</code></li>
	<li><code>-2<sup>31</sup> &lt;= x<sub>start</sub> &lt;&nbsp;x<sub>end</sub> &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)
* [Non-overlapping Intervals (Medium)](https://leetcode.com/problems/non-overlapping-intervals/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& A) {
        if (A.empty()) return 0;
        sort(begin(A), end(A));
        int ans = 1, arrow = A[0][1];
        for (auto &b : A) {
            if (b[0] <= arrow) arrow = min(arrow, b[1]);
            else {
                arrow = b[1];
                ++ans;
            }
        }
        return ans;
    }
};
```
