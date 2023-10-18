# [2406. Divide Intervals Into Minimum Number of Groups (Medium)](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups)

<p>You are given a 2D integer array <code>intervals</code> where <code>intervals[i] = [left<sub>i</sub>, right<sub>i</sub>]</code> represents the <strong>inclusive</strong> interval <code>[left<sub>i</sub>, right<sub>i</sub>]</code>.</p>

<p>You have to divide the intervals into one or more <strong>groups</strong> such that each interval is in <strong>exactly</strong> one group, and no two intervals that are in the same group <strong>intersect</strong> each other.</p>

<p>Return <em>the <strong>minimum</strong> number of groups you need to make</em>.</p>

<p>Two intervals <strong>intersect</strong> if there is at least one common number between them. For example, the intervals <code>[1, 5]</code> and <code>[5, 8]</code> intersect.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,3],[5,6],[8,10],[11,13]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> None of the intervals overlap, so we can put all of them in one group.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>1 &lt;= left<sub>i</sub> &lt;= right<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Two Pointers](https://leetcode.com/tag/two-pointers), [Greedy](https://leetcode.com/tag/greedy), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals)
* [Minimum Number of Frogs Croaking (Medium)](https://leetcode.com/problems/minimum-number-of-frogs-croaking)
* [Average Height of Buildings in Each Segment (Medium)](https://leetcode.com/problems/average-height-of-buildings-in-each-segment)

**Hints**:
* Can you find a different way to describe the question?
* The minimum number of groups we need is equivalent to the maximum number of intervals that overlap at some point. How can you find that?

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minGroups(vector<vector<int>>& A) {
        multiset<vector<int>> s(begin(A), end(A)); // Sort intervals in ascending order of start time
        int ans = 0;
        while (s.size()) {
            auto it = s.begin();
            while (it != s.end()) {
                int R = (*it)[1];
                s.erase(it);
                it = s.lower_bound({R+1,0}); // Greedily pick the earliest interval whose start time is after the previously picked interval's end time
            }
            ++ans;
        }
        return ans;
    }
};
```

## Solution 2. Min Heap

```cpp
// OJ: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minGroups(vector<vector<int>>& A) {
        sort(begin(A), end(A)); // sort intervals in ascending order of start time
        priority_queue<int, vector<int>, greater<>> pq; // min heap of end times of active intervals
        int ans = 0;
        for (auto &v : A) {
            int left = v[0], right = v[1];
            while (pq.size() && pq.top() < left) pq.pop(); // deactivate all the intervals ends before the current one
            pq.push(right); // activate the current interval
            ans = max(ans, (int)pq.size()); // Try updating answer with the number of active intervals.
        }
        return ans;
    }
};
```