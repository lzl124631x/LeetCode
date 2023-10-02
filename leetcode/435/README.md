# [435. Non-overlapping Intervals (Medium)](https://leetcode.com/problems/non-overlapping-intervals)

<p>Given an array of intervals <code>intervals</code> where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, return <em>the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> intervals = [[1,2],[2,3],[3,4],[1,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> [1,3] can be removed and the rest of the intervals are non-overlapping.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> intervals = [[1,2],[1,2],[1,2]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You need to remove two [1,2] to make the rest of the intervals non-overlapping.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> intervals = [[1,2],[2,3]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> You don't need to remove any of the intervals since they're already non-overlapping.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>-5 * 10<sup>4</sup> &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 5 * 10<sup>4</sup></code></li>
</ul>

**Companies**:
[JPMorgan](https://leetcode.com/company/jpmorgan), [Amazon](https://leetcode.com/company/amazon), [Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Minimum Number of Arrows to Burst Balloons (Medium)](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)
* [Determine if Two Events Have Conflict (Easy)](https://leetcode.com/problems/determine-if-two-events-have-conflict/)

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