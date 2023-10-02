# [218. The Skyline Problem (Hard)](https://leetcode.com/problems/the-skyline-problem/)

<p>A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are <b>given the locations and height of all the buildings</b> as shown on a cityscape photo (Figure A), write a program to <b>output the skyline</b> formed by these buildings collectively (Figure B).</p>
<a href="/static/images/problemset/skyline1.jpg" target="_blank"><img alt="Buildings" src="https://assets.leetcode.com/uploads/2018/10/22/skyline1.png" style="max-width: 45%; border-width: 0px; border-style: solid;"> </a> <a href="/static/images/problemset/skyline2.jpg" target="_blank"> <img alt="Skyline Contour" src="https://assets.leetcode.com/uploads/2018/10/22/skyline2.png" style="max-width: 45%; border-width: 0px; border-style: solid;"> </a>

<p>The geometric information of each building is represented by a triplet of integers <code>[Li, Ri, Hi]</code>, where <code>Li</code> and <code>Ri</code> are the x coordinates of the left and right edge of the ith building, respectively, and <code>Hi</code> is its height. It is guaranteed that <code>0 ≤ Li, Ri ≤ INT_MAX</code>, <code>0 &lt; Hi ≤ INT_MAX</code>, and <code>Ri - Li &gt; 0</code>. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.</p>

<p>For instance, the dimensions of all buildings in Figure A are recorded as: <code>[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] </code>.</p>

<p>The output is a list of "<b>key points</b>" (red dots in Figure B) in the format of <code>[ [x1,y1], [x2, y2], [x3, y3], ... ]</code> that uniquely defines a skyline. <b>A key point is the left endpoint of a horizontal line segment</b>. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.</p>

<p>For instance, the skyline in Figure B should be represented as:<code>[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]</code>.</p>

<p><b>Notes:</b></p>

<ul>
	<li>The number of buildings in any input list is guaranteed to be in the range <code>[0, 10000]</code>.</li>
	<li>The input list is already sorted in ascending order by the left x position <code>Li</code>.</li>
	<li>The output list must be sorted by the x position.</li>
	<li>There must be no consecutive horizontal lines of equal height in the output skyline. For instance, <code>[...[2 3], [4 5], [7 5], [11 5], [12 7]...]</code> is not acceptable; the three lines of height 5 should be merged into one in the final output as such: <code>[...[2 3], [4 5], [12 7], ...]</code></li>
</ul>


**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Heap](https://leetcode.com/tag/heap/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Line Sweep](https://leetcode.com/tag/line-sweep/)

**Similar Questions**:
* [Falling Squares (Hard)](https://leetcode.com/problems/falling-squares/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/the-skyline-problem/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/14939/my-c-code-using-one-priority-queue-812-ms
bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
         vector<pair<int, int>> ans;
         sort(buildings.begin(), buildings.end(), cmp);
         int i = 0, x = 0, y = 0, N = buildings.size();
         priority_queue<pair<int, int>> live;// first: height, second: right
         while (i < N || !live.empty()) {
             if (i < N && (live.empty() || live.top().second >= buildings[i][0])) {
                 x = buildings[i][0];
                 while (i < N && buildings[i][0] == x) {
                     live.push(make_pair(buildings[i][2], buildings[i][1]));
                     ++i;
                 }
             } else {
                 x = live.top().second;
                 while (!live.empty() && live.top().second <= x) live.pop();
             }
             y = live.empty() ? 0 : live.top().first;
             if (ans.empty() || ans.back().second != y) ans.push_back(make_pair(x, y));
         }
         return ans;
    }
};
```