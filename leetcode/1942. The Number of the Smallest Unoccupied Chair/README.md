# [1942. The Number of the Smallest Unoccupied Chair (Medium)](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/)

<p>There is a party where <code>n</code> friends numbered from <code>0</code> to <code>n - 1</code> are attending. There is an <strong>infinite</strong> number of chairs in this party that are numbered from <code>0</code> to <code>infinity</code>. When a friend arrives at the party, they sit on the unoccupied chair with the <strong>smallest number</strong>.</p>

<ul>
	<li>For example, if chairs <code>0</code>, <code>1</code>, and <code>5</code> are occupied when a friend comes, they will sit on chair number <code>2</code>.</li>
</ul>

<p>When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.</p>

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>times</code> where <code>times[i] = [arrival<sub>i</sub>, leaving<sub>i</sub>]</code>, indicating the arrival and leaving times of the <code>i<sup>th</sup></code> friend respectively, and an integer <code>targetFriend</code>. All arrival times are <strong>distinct</strong>.</p>

<p>Return<em> the <strong>chair number</strong> that the friend numbered </em><code>targetFriend</code><em> will sit on</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> times = [[1,4],[2,3],[4,6]], targetFriend = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> times = [[3,10],[1,5],[2,6]], targetFriend = 0
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == times.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>times[i].length == 2</code></li>
	<li><code>1 &lt;= arrival<sub>i</sub> &lt; leaving<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= targetFriend &lt;= n - 1</code></li>
	<li>Each <code>arrival<sub>i</sub></code> time is <strong>distinct</strong>.</li>
</ul>


## Solution 1. Heap 

```cpp
// OJ: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int smallestChair(vector<vector<int>>& A, int targetFriend) {
        set<int> avail; // indices of available seats
        for (int i = 0; i < A.size(); ++i) avail.insert(i);
        auto target = A[targetFriend][0];
        sort(begin(A), end(A));
        auto cmp = [&](int a, int b) { return A[a][1] > A[b][1]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); // min heap of indices of friends in seats. Friend at heap top has the earliest leave time
        unordered_map<int, int> seat; // mapping from friend index to seat index
        for (int i = 0; i < A.size(); ++i) {
            auto &v = A[i];
            while (pq.size() && A[pq.top()][1] <= v[0]) { // given the current arrival time, pop all the friends that have left
                int s = seat[pq.top()];
                avail.insert(s); // free the corresponding seat
                seat.erase(i);
                pq.pop();
            }
            int s = *avail.begin(); // take the seat with the smallest index available
            if (v[0] == target) return s;
            avail.erase(s);
            seat[i] = s;
            pq.push(i);
        }
        return -1;
    }
};
```

Or shorter code

```cpp
// OJ: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int smallestChair(vector<vector<int>>& A, int targetFriend) {
        int target = A[targetFriend][0];
        sort(begin(A), end(A));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> used; // leave time, seat
        priority_queue<int, vector<int>, greater<>> avail;
        for (int i = 0; i < A.size(); ++i) avail.push(i);
        for (int i = 0; i < A.size(); ++i) {
            auto &v = A[i];
            while (used.size() && used.top().first <= v[0]) {
                avail.push(used.top().second);
                used.pop();
            }
            int s = avail.top();
            avail.pop();
            if (v[0] == target) return s;
            used.emplace(v[1], s);
        }
        return -1;
    }
};
```