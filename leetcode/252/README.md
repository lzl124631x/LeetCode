# [252. Meeting Rooms (Easy)](https://leetcode.com/problems/meeting-rooms/)

<p>Given an array of meeting time intervals consisting of start and end times <code>[[s1,e1],[s2,e2],...]</code> (s<sub>i</sub> &lt; e<sub>i</sub>), determine if a person could attend all meetings.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> <code>[[0,30],[5,10],[15,20]]</code>
<b>Output:</b> false
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [[7,10],[2,4]]
<b>Output:</b> true
</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/meeting-rooms/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](Interval &a, Interval &b) {
            return a.start < b.start;
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
    }
};
```