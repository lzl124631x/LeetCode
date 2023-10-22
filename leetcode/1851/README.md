# [1851. Minimum Interval to Include Each Query (Hard)](https://leetcode.com/problems/minimum-interval-to-include-each-query)

<p>You are given a 2D integer array <code>intervals</code>, where <code>intervals[i] = [left<sub>i</sub>, right<sub>i</sub>]</code> describes the <code>i<sup>th</sup></code> interval starting at <code>left<sub>i</sub></code> and ending at <code>right<sub>i</sub></code> <strong>(inclusive)</strong>. The <strong>size</strong> of an interval is defined as the number of integers it contains, or more formally <code>right<sub>i</sub> - left<sub>i</sub> + 1</code>.</p>

<p>You are also given an integer array <code>queries</code>. The answer to the <code>j<sup>th</sup></code> query is the <strong>size of the smallest interval</strong> <code>i</code> such that <code>left<sub>i</sub> &lt;= queries[j] &lt;= right<sub>i</sub></code>. If no such interval exists, the answer is <code>-1</code>.</p>

<p>Return <em>an array containing the answers to the queries</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
<strong>Output:</strong> [3,3,1,4]
<strong>Explanation:</strong> The queries are processed as follows:
- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
<strong>Output:</strong> [2,-1,4,6]
<strong>Explanation:</strong> The queries are processed as follows:
- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
- Query = 19: None of the intervals contain 19. The answer is -1.
- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>1 &lt;= left<sub>i</sub> &lt;= right<sub>i</sub> &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= queries[j] &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Line Sweep](https://leetcode.com/tag/line-sweep), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue)

**Similar Questions**:
* [Number of Flowers in Full Bloom (Hard)](https://leetcode.com/problems/number-of-flowers-in-full-bloom)

**Hints**:
* Is there a way to order the intervals and queries such that it takes less time to query?
* Is there a way to add and remove intervals by going from the smallest query to the largest query to find the minimum size?

## Solution 1. Offline Query + Sliding Window + Min Heap

**Intuition**: We can sort the intervals and queries in ascending order. For each query `q`, we can maintain a sliding window on the intervals array covering the range of intervals that might contain the query `q`.

**Algorithm**

Sort both the intervals array `A` and the queries array `QQ` in ascending order.

Assume the current query is `q`, we use a read pointer `i` as the right edge of the sliding window to keep reading intervals whose left edge `<= q`. For each interval we read, we increment the count of the interval length in map `m` and push the right edge and length into a min heap `pq`.

Then we keep popping intervals from the min heap whose right edge `< q`, and decrement the count.

In this way, the map `m` stores the lengths of all valid intervals covering the current query, and their corresponding count. We use the smallest length as the answer to the current query.

### Complexity Analysis

Sorting both arrays take `O(NlogN + QlogQ)` time and `O(Q)` space.

For each query, we need to access the map `m` and the min heap `pq` which could contain `O(N)` elements (i.e. takes `O(N)` space), so updating them takes `O(logN)` time.

Note that each interval enters the min heap at most once, so this takes amortized `O(NlogN)` time.

So overall, this solution takes `O(NlogN + QlogQ)` time and `O(N + Q)` space

```cpp
// OJ: https://leetcode.com/problems/minimum-interval-to-include-each-query/
// Author: github.com/lzl124631x
// Time: O(NlogN + QlogQ + QlogN)
// Space: O(N + Q)
class Solution {
    typedef pair<int, int> T;
public:
    vector<int> minInterval(vector<vector<int>>& A, vector<int>& Q) {
        vector<pair<int, int>> QQ; // each element is a pair of query and the corresponding index
        for (int i = 0; i < Q.size(); ++i) QQ.emplace_back(Q[i], i); 
        sort(begin(QQ), end(QQ)); // sort in ascending order of query
        sort(begin(A), end(A)); // sort intervals in ascending order
        int i = 0, N = A.size(); // `i` is a read pointer scanning `A`.
        vector<int> ans(Q.size(), -1);
        map<int, int> m; // map `m` stores the mapping from a interval length to its corresponding count.
        priority_queue<T, vector<T>, greater<>> pq; // min-heap. Each element is a pair of right edge and interval length
        for (auto &[q, index] : QQ) {
            for (; i < N && A[i][0] <= q; ++i) { // extend the window's right edge -- cover all the intervals whose left edge <= q
                int len = A[i][1] - A[i][0] + 1;
                m[len]++;
                pq.emplace(A[i][1], len);
            }
            while (pq.size() && pq.top().first < q) { // shrink the window's left edge -- pop all the intervals whose right edge < q
                auto [right, len] = pq.top();
                if (--m[len] == 0) m.erase(len);
                pq.pop();
            }
            if (m.size()) ans[index] = m.begin()->first; // the map `m` stores the length of all the valid intervals and their corresponding count. We use the smallest length.
        }
        return ans;
    }
};
```