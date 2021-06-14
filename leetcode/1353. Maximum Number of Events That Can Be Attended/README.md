# [1353. Maximum Number of Events That Can Be Attended (Medium)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)

<p>Given an array of <code>events</code> where <code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>]</code>. Every event <code>i</code> starts at&nbsp;<code>startDay<sub>i</sub></code><sub>&nbsp;</sub>and ends at&nbsp;<code>endDay<sub>i</sub></code>.</p>

<p>You can attend an event <code>i</code>&nbsp;at any day&nbsp;<code>d</code> where&nbsp;<code>startTime<sub>i</sub>&nbsp;&lt;= d &lt;= endTime<sub>i</sub></code>. Notice that you can only attend one event at any time <code>d</code>.</p>

<p>Return <em>the maximum number of events&nbsp;</em>you can attend.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/05/e1.png" style="width: 660px; height: 440px;">
<pre><strong>Input:</strong> events = [[1,2],[2,3],[3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> events= [[1,2],[2,3],[3,4],[1,2]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> events = [[1,100000]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
	<li><code>events[i].length == 2</code></li>
	<li><code>1 &lt;= startDay<sub>i</sub> &lt;= endDay<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Infosys](https://leetcode.com/company/infosys)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/), [Segment Tree](https://leetcode.com/tag/segment-tree/)

**Similar Questions**:
* [Maximum Number of Events That Can Be Attended II (Hard)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

## Solution 1. Greedy

Sort the events in ascending order of the start time.

Let `day` be the current day and it starts with `A[0][0]`.

If an event starts at `day`, we start to take it into consideration.

If an event ends before `day`, we can ignore it.

If an event starts no later than `day` and ends after `day`, we call it an active event.

Use a `priority_queue` to keep track of the end times of active events, and greedily pick the event with the earliest end time.

[Here](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510262/Detailed-analysisLet-me-lead-you-to-the-solution-step-by-step) is a very good article explaining the reasoning step by step.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        priority_queue<int, vector<int>, greater<>> pq;
        int N = A.size(), i = 0, day = A[0][0], ans = 0;
        while (i < N || pq.size()) {
            if (pq.empty()) day = A[i][0]; // If no active event is available and there are still more events to pick, jump to the start date of the next event.
            while (i < N && A[i][0] == day) pq.push(A[i++][1]); // add events that start at `day` as active events, push their end time into queue
            pq.pop(); // pick the event with the earliest start time
            ++ans;
            ++day;
            while (pq.size() && pq.top() < day) pq.pop(); // ignore the events that are no longer active
        }
        return ans;
    }
};
```

## Note

Similar to [1834. Single-Threaded CPU (Medium)](https://leetcode.com/problems/single-threaded-cpu/)