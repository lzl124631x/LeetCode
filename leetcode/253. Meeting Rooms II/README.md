# [253. Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)

<p>Given an array of meeting time intervals <code>intervals</code> where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, return <em>the minimum number of conference rooms required</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> intervals = [[0,30],[5,10],[15,20]]
<strong>Output:</strong> 2
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> intervals = [[7,10],[2,4]]
<strong>Output:</strong> 1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Oracle](https://leetcode.com/company/oracle), [Walmart Labs](https://leetcode.com/company/walmart-labs), [ByteDance](https://leetcode.com/company/bytedance), [Uber](https://leetcode.com/company/uber), [Twitter](https://leetcode.com/company/twitter), [Snapchat](https://leetcode.com/company/snapchat), [Yahoo](https://leetcode.com/company/yahoo), [VMware](https://leetcode.com/company/vmware), [Quora](https://leetcode.com/company/quora), [Visa](https://leetcode.com/company/visa), [Swiggy](https://leetcode.com/company/swiggy)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Meeting Rooms (Easy)](https://leetcode.com/problems/meeting-rooms/)
* [Minimum Number of Arrows to Burst Balloons (Medium)](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)
* [Car Pooling (Medium)](https://leetcode.com/problems/car-pooling/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/meeting-rooms-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) {
        vector<int> starts, ends;
        for (auto &v : A) {
            starts.push_back(v[0]);
            ends.push_back(v[1]);
        }
        sort(begin(starts), end(starts));
        sort(begin(ends), end(ends));
        int N = A.size(), ans = 0, cnt = 0;
        for (int i = 0, j = 0; i < N;) {
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

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/meeting-rooms-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) {
        vector<int> starts, ends;
        for (auto &v : A) {
            starts.push_back(v[0]);
            ends.push_back(v[1]);
        }
        sort(begin(starts), end(starts));
        sort(begin(ends), end(ends));
        int N = A.size(), ans = 0;
        for (int i = 0, j = 0; i < N; ++ans, ++i) {
            if (starts[i] < ends[j]) continue;
            --ans;
            ++j;
        }
        return ans;
    }
};
```

## Solution 3. Heap

```cpp
// OJ: https://leetcode.com/problems/meeting-rooms-ii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) {
        int N = A.size(), ans = 0;
        sort(begin(A), end(A));
        auto cmp = [&](int a, int b) { return A[a][1] > A[b][1]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); 
        for (int i = 0; i < N; ++i) {
            int start = A[i][0];
            while (pq.size() && A[pq.top()][1] <= start) pq.pop();
            pq.push(i);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
```