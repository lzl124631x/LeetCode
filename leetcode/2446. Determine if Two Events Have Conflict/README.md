# [2446. Determine if Two Events Have Conflict (Easy)](https://leetcode.com/problems/determine-if-two-events-have-conflict)

<p>You are given two arrays of strings that represent two inclusive events that happened <strong>on the same day</strong>, <code>event1</code> and <code>event2</code>, where:</p>
<ul>
	<li><code>event1 = [startTime<sub>1</sub>, endTime<sub>1</sub>]</code> and</li>
	<li><code>event2 = [startTime<sub>2</sub>, endTime<sub>2</sub>]</code>.</li>
</ul>
<p>Event times are valid 24 hours format in the form of <code>HH:MM</code>.</p>
<p>A <strong>conflict</strong> happens when two events have some non-empty intersection (i.e., some moment is common to both events).</p>
<p>Return <code>true</code><em> if there is a conflict between two events. Otherwise, return </em><code>false</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
<strong>Output:</strong> true
<strong>Explanation:</strong> The two events intersect at time 2:00.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
<strong>Output:</strong> true
<strong>Explanation:</strong> The two events intersect starting from 01:20 to 02:00.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
<strong>Output:</strong> false
<strong>Explanation:</strong> The two events do not intersect.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>evnet1.length == event2.length == 2.</code></li>
	<li><code>event1[i].length == event2[i].length == 5</code></li>
	<li><code>startTime<sub>1</sub> &lt;= endTime<sub>1</sub></code></li>
	<li><code>startTime<sub>2</sub> &lt;= endTime<sub>2</sub></code></li>
	<li>All the event times follow the <code>HH:MM</code> format.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Non-overlapping Intervals (Medium)](https://leetcode.com/problems/non-overlapping-intervals/)
* [My Calendar I (Medium)](https://leetcode.com/problems/my-calendar-i/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/determine-if-two-events-have-conflict
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    int time(string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
public:
    bool haveConflict(vector<string>& A, vector<string>& B) {
        int a = time(A[0]), b = time(A[1]), c = time(B[0]), d = time(B[1]);
        if (a > c) swap(a, c), swap(b, d);
        return c <= b;
    }
};
```