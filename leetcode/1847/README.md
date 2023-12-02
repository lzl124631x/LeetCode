# [1847. Closest Room (Hard)](https://leetcode.com/problems/closest-room)

<p>There is a hotel with <code>n</code> rooms. The rooms are represented by a 2D integer array <code>rooms</code> where <code>rooms[i] = [roomId<sub>i</sub>, size<sub>i</sub>]</code> denotes that there is a room with room number <code>roomId<sub>i</sub></code> and size equal to <code>size<sub>i</sub></code>. Each <code>roomId<sub>i</sub></code> is guaranteed to be <strong>unique</strong>.</p>

<p>You are also given <code>k</code> queries in a 2D array <code>queries</code> where <code>queries[j] = [preferred<sub>j</sub>, minSize<sub>j</sub>]</code>. The answer to the <code>j<sup>th</sup></code> query is the room number <code>id</code> of a room such that:</p>

<ul>
	<li>The room has a size of <strong>at least</strong> <code>minSize<sub>j</sub></code>, and</li>
	<li><code>abs(id - preferred<sub>j</sub>)</code> is <strong>minimized</strong>, where <code>abs(x)</code> is the absolute value of <code>x</code>.</li>
</ul>

<p>If there is a <strong>tie</strong> in the absolute difference, then use the room with the <strong>smallest</strong> such <code>id</code>. If there is <strong>no such room</strong>, the answer is <code>-1</code>.</p>

<p>Return <em>an array </em><code>answer</code><em> of length </em><code>k</code><em> where </em><code>answer[j]</code><em> contains the answer to the </em><code>j<sup>th</sup></code><em> query</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
<strong>Output:</strong> [3,-1,3]
<strong>Explanation: </strong>The answers to the queries are as follows:
Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, and its size of 2 is at least 1. The answer is 3.
Query = [3,3]: There are no rooms with a size of at least 3, so the answer is -1.
Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, and its size of 2 is at least 2. The answer is 3.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
<strong>Output:</strong> [2,1,3]
<strong>Explanation: </strong>The answers to the queries are as follows:
Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, and its size of 3 is at least 3. The answer is 2.
Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. The answer is 1 since it is smaller.
Query = [2,5]: Room number 3 is the only room with a size of at least 5. The answer is 3.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == rooms.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>k == queries.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= roomId<sub>i</sub>, preferred<sub>j</sub> &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= size<sub>i</sub>, minSize<sub>j</sub> &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [Most Beautiful Item for Each Query (Medium)](https://leetcode.com/problems/most-beautiful-item-for-each-query)
* [Minimum Time to Kill All Monsters (Hard)](https://leetcode.com/problems/minimum-time-to-kill-all-monsters)

**Hints**:
* Is there a way to sort the queries so it's easier to search the closest room larger than the size?
* Use binary search to speed up the search time.

## Solution 1. Offline Query

```cpp
// OJ: https://leetcode.com/problems/closest-room/
// Author: github.com/lzl124631x
// Time: O(RlogR + QlogQ + QlogR)
// Space: O(R)
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& R, vector<vector<int>>& Q) {
        for (int i = 0; i < Q.size(); ++i) Q[i].push_back(i);
        sort(begin(Q), end(Q), [](auto &a, auto &b) { return a[1] > b[1]; });
        sort(begin(R), end(R), [](auto &a, auto &b) { return a[1] > b[1]; });
        set<int> ids;
        vector<int> ans(Q.size());
        int i = 0, N = R.size();
        for (auto &q : Q) {
            int pref = q[0], mn = q[1], idx = q[2], id = -1, diff = INT_MAX;
            while (i < N && R[i][1] >= mn) ids.insert(R[i++][0]);
            auto it = ids.upper_bound(pref);
            if (it != ids.end()) id = *it, diff = id - pref;
            if (it != ids.begin() && pref - *prev(it) <= diff) id = *prev(it);
            ans[idx] = id;
        }
        return ans;
    }
};
```