# [435. Non-overlapping Intervals (Medium)](https://leetcode.com/problems/non-overlapping-intervals/)

<p>Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [[1,2],[2,3],[3,4],[1,3]]
<b>Output:</b> 1
<b>Explanation:</b> [1,3] can be removed and the rest of intervals are non-overlapping.
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [[1,2],[1,2],[1,2]]
<b>Output:</b> 2
<b>Explanation:</b> You need to remove two [1,2] to make the rest of intervals non-overlapping.
</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> [[1,2],[2,3]]
<b>Output:</b> 0
<b>Explanation:</b> You don't need to remove any of the intervals since they're already non-overlapping.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>You may assume the interval's end point is always bigger than its start point.</li>
	<li>Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.</li>
</ol>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Number of Arrows to Burst Balloons (Medium)](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)

## Solution 1. Interval Scheduling Maximization Problem

```cpp
// OJ: https://leetcode.com/problems/non-overlapping-intervals/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        int ans = 0, e = INT_MIN;
        for (auto &v : A) {
            if (v[0] >= e) e = v[1];
            else ++ans;
        }
        return ans;
    }
};
```