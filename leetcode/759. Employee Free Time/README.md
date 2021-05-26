# [759. Employee Free Time (Hard)](https://leetcode.com/problems/employee-free-time/)

<p>We are given a list <code>schedule</code> of employees, which represents the working time for each employee.</p>

<p>Each employee has a list of non-overlapping <code>Intervals</code>, and these intervals are in sorted order.</p>

<p>Return the list of finite intervals representing <b>common, positive-length free time</b> for <i>all</i> employees, also in sorted order.</p>

<p>(Even though we are representing <code>Intervals</code> in the form <code>[x, y]</code>, the objects inside are <code>Intervals</code>, not lists or arrays. For example, <code>schedule[0][0].start = 1</code>, <code>schedule[0][0].end = 2</code>, and <code>schedule[0][0][0]</code> is not defined).&nbsp; Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
<strong>Output:</strong> [[3,4]]
<strong>Explanation:</strong> There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
<strong>Output:</strong> [[5,6],[7,9]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= schedule.length , schedule[i].length &lt;= 50</code></li>
	<li><code>0 &lt;= schedule[i].start &lt; schedule[i].end &lt;= 10^8</code></li>
</ul>


**Companies**:  
[DoorDash](https://leetcode.com/company/doordash), [Amazon](https://leetcode.com/company/amazon), [Pinterest](https://leetcode.com/company/pinterest), [Wayfair](https://leetcode.com/company/wayfair), [Intuit](https://leetcode.com/company/intuit), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Interval List Intersections (Medium)](https://leetcode.com/problems/interval-list-intersections/)

## Solution 1. Line Sweep

```cpp
// OJ: https://leetcode.com/problems/employee-free-time/
// Author: github.com/lzl124631x
// Time: O(NlogT + T) where N is the total number of intervals, and T is the total number of unique times.
// Space: O(T)
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> A) {
        map<int, int> m;
        for (auto &v : A) {
            for (auto &it : v) {
                m[it.start]++;
                m[it.end]--;
            }
        }
        vector<Interval> ans;
        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            cnt += it->second;
            if (cnt) continue;
            int start = it->first;
            ++it;
            if (it == m.end()) break;
            cnt += it->second;
            ans.emplace_back(start, it->first);
        }
        return ans;
    }
};
```