# [2054. Two Best Non-Overlapping Events (Medium)](https://leetcode.com/problems/two-best-non-overlapping-events/)

<p>You are given a <strong>0-indexed</strong> 2D integer array of <code>events</code> where <code>events[i] = [startTime<sub>i</sub>, endTime<sub>i</sub>, value<sub>i</sub>]</code>. The <code>i<sup>th</sup></code> event starts at <code>startTime<sub>i</sub></code><sub> </sub>and ends at <code>endTime<sub>i</sub></code>, and if you attend this event, you will receive a value of <code>value<sub>i</sub></code>. You can choose <strong>at most</strong> <strong>two</strong> <strong>non-overlapping</strong> events to attend such that the sum of their values is <strong>maximized</strong>.</p>

<p>Return <em>this <strong>maximum</strong> sum.</em></p>

<p>Note that the start time and end time is <strong>inclusive</strong>: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time <code>t</code>, the next event must start at or after <code>t + 1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/picture5.png" style="width: 400px; height: 75px;">
<pre><strong>Input:</strong> events = [[1,3,2],[4,5,2],[2,4,3]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="Example 1 Diagram" src="https://assets.leetcode.com/uploads/2021/09/21/picture1.png" style="width: 400px; height: 77px;">
<pre><strong>Input:</strong> events = [[1,3,2],[4,5,2],[1,5,5]]
<strong>Output:</strong> 5
<strong>Explanation: </strong>Choose event 2 for a sum of 5.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/picture3.png" style="width: 400px; height: 66px;">
<pre><strong>Input:</strong> events = [[1,5,3],[1,5,1],[6,6,5]]
<strong>Output:</strong> 8
<strong>Explanation: </strong>Choose events 0 and 2 for a sum of 3 + 5 = 8.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
	<li><code>events[i].length == 3</code></li>
	<li><code>1 &lt;= startTime<sub>i</sub> &lt;= endTime<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= value<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:  
[razorpay](https://leetcode.com/company/razorpay)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

**Similar Questions**:
* [Maximum Profit in Job Scheduling (Hard)](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)
* [Maximum Number of Events That Can Be Attended II (Hard)](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

## Solution 1. Mono-stack

```cpp
// OJ: https://leetcode.com/problems/two-best-non-overlapping-events/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int N = A.size(), ans = 0, mx = 0;
        stack<pair<int, int>> s; // startTime, val
        for (int i = N - 1; i >= 0; --i) {
            if (s.empty() || s.top().second < A[i][2]) s.emplace(A[i][0], A[i][2]);
            ans = max(ans, A[i][2]);
        }
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        for (int i = 0; i < N && s.size(); ++i) {
            while (s.size() && s.top().first <= A[i][1]) s.pop();
            mx = max(mx, A[i][2]);
            if (s.size()) ans = max(ans, mx + s.top().second);
        }
        return ans;
    }
};
```

## Solution 2. Map + Binary Search

```cpp
// OJ: https://leetcode.com/problems/two-best-non-overlapping-events/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int N = A.size(), ans = 0;
        map<int, int> m;
        for (int i = N - 1, mx = 0; i >= 0; --i) {
            m[A[i][0]] = (mx = max(mx, A[i][2]));
            ans = max(ans, A[i][2]);
        }
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        for (int i = 0, mx = 0; i < N; ++i) {
            mx = max(mx, A[i][2]);
            auto it = m.upper_bound(A[i][1]);
            if (it != m.end()) ans = max(ans, mx + it->second);
        }
        return ans;
    }
};
```

## Solution 3. Map + Binary Search

```cpp
// OJ: https://leetcode.com/problems/two-best-non-overlapping-events/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int N = A.size(), ans = 0, mx = 0;
        map<int, int> m;  // startTime -> maxVal
        for (int i = N - 1; i >= 0; --i) {
            mx = max(mx, A[i][2]);
            auto it = m.upper_bound(A[i][1]);
            if (it != m.end()) ans = max(ans, A[i][2] + it->second);
            m[A[i][0]] = mx;
        }
        return max(ans, mx);
    }
};
```

## Solution 4. Line Sweep

```cpp
// OJ: https://leetcode.com/problems/two-best-non-overlapping-events/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/two-best-non-overlapping-events/discuss/1552570/Very-Simple-sort-%2B-greedy%3A-No-DP-no-Binary-Search-no-HeapPQBST
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& A) {
        vector<array<int, 3>> B; // time, isStart, value
        for (auto &e : A) {
            B.push_back({ e[0], 1, e[2] });
            B.push_back({ e[1] + 1, 0, e[2] });
        }
        sort(begin(B), end(B));
        int ans = 0, maxEndValue = 0;
        for (auto &[time, isStart, value] : B) {
            if (isStart) ans = max(ans, value + maxEndValue);
            else maxEndValue = max(maxEndValue, value);
        }
        return ans;
    }
};
```