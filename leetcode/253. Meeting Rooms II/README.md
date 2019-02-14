# [253. Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)

<p>Given an array of meeting time intervals consisting of start and end times <code>[[s1,e1],[s2,e2],...]</code> (s<sub>i</sub> &lt; e<sub>i</sub>), find the minimum number of conference rooms required.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>[[0, 30],[5, 10],[15, 20]]</code>
<strong>Output:</strong> 2</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [[7,10],[2,4]]
<b>Output:</b> 1</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Uber](https://leetcode.com/company/uber), [Yelp](https://leetcode.com/company/yelp), [Apple](https://leetcode.com/company/apple), [Snapchat](https://leetcode.com/company/snapchat), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Meeting Rooms (Easy)](https://leetcode.com/problems/meeting-rooms/)
* [Minimum Number of Arrows to Burst Balloons (Medium)](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/meeting-rooms-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (auto &i : intervals) {
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int ans = 0, cnt = 0;
        for (int i = 0, j = 0, N = intervals.size(); i < N;) {
            if (starts[i] < ends[j]) {
                ++cnt;
                ++i;
                ans = max(ans, cnt);
            } else if (starts[i] > ends[j]) {
                --cnt;
                ++j;
            } else {
                ++i;
                ++j;
            }
        }
        return ans;
    }
};
```