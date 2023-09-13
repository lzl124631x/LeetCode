# [56. Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)

<p>Given an array&nbsp;of <code>intervals</code>&nbsp;where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, merge all overlapping intervals, and return <em>an array of the non-overlapping intervals that cover all the intervals in the input</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,3],[2,6],[8,10],[15,18]]
<strong>Output:</strong> [[1,6],[8,10],[15,18]]
<strong>Explanation:</strong> Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,4],[4,5]]
<strong>Output:</strong> [[1,5]]
<strong>Explanation:</strong> Intervals [1,4] and [4,5] are considered overlapping.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Insert Interval (Medium)](https://leetcode.com/problems/insert-interval/)
* [Meeting Rooms (Easy)](https://leetcode.com/problems/meeting-rooms/)
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)
* [Teemo Attacking (Medium)](https://leetcode.com/problems/teemo-attacking/)
* [Add Bold Tag in String (Medium)](https://leetcode.com/problems/add-bold-tag-in-string/)
* [Range Module (Hard)](https://leetcode.com/problems/range-module/)
* [Employee Free Time (Hard)](https://leetcode.com/problems/employee-free-time/)
* [Partition Labels (Medium)](https://leetcode.com/problems/partition-labels/)
* [Interval List Intersections (Medium)](https://leetcode.com/problems/interval-list-intersections/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/merge-intervals/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        for (auto &v : A) {
            if (ans.empty() || v[0] > ans.back()[1]) ans.push_back(v);
            else ans.back()[1] = max(ans.back()[1], v[1]);
        }
        return ans;
    }
};
```