# [2940. Find Building Where Alice and Bob Can Meet (Hard)](https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet)

<p>You are given a <strong>0-indexed</strong> array <code>heights</code> of positive integers, where <code>heights[i]</code> represents the height of the <code>i<sup>th</sup></code> building.</p>

<p>If a person is in building <code>i</code>, they can move to any other building <code>j</code> if and only if <code>i &lt; j</code> and <code>heights[i] &lt; heights[j]</code>.</p>

<p>You are also given another array <code>queries</code> where <code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>. On the <code>i<sup>th</sup></code> query, Alice is in building <code>a<sub>i</sub></code> while Bob is in building <code>b<sub>i</sub></code>.</p>

<p>Return <em>an array</em> <code>ans</code> <em>where</em> <code>ans[i]</code> <em>is <strong>the index of the leftmost building</strong> where Alice and Bob can meet on the</em> <code>i<sup>th</sup></code> <em>query</em>. <em>If Alice and Bob cannot move to a common building on query</em> <code>i</code>, <em>set</em> <code>ans[i]</code> <em>to</em> <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
<strong>Output:</strong> [2,5,-1,5,2]
<strong>Explanation:</strong> In the first query, Alice and Bob can move to building 2 since heights[0] &lt; heights[2] and heights[1] &lt; heights[2]. 
In the second query, Alice and Bob can move to building 5 since heights[0] &lt; heights[5] and heights[3] &lt; heights[5]. 
In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
In the fourth query, Alice and Bob can move to building 5 since heights[3] &lt; heights[5] and heights[4] &lt; heights[5].
In the fifth query, Alice and Bob are already in the same building.  
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
<strong>Output:</strong> [7,6,-1,4,6]
<strong>Explanation:</strong> In the first query, Alice can directly move to Bob&#39;s building since heights[0] &lt; heights[7].
In the second query, Alice and Bob can move to building 6 since heights[3] &lt; heights[6] and heights[5] &lt; heights[6].
In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
In the fourth query, Alice and Bob can move to building 4 since heights[3] &lt; heights[4] and heights[0] &lt; heights[4].
In the fifth query, Alice can directly move to Bob&#39;s building since heights[1] &lt; heights[6].
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= heights.length - 1</code></li>
</ul>


**Companies**:
[Infosys](https://leetcode.com/company/infosys)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Stack](https://leetcode.com/tag/stack), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree), [Segment Tree](https://leetcode.com/tag/segment-tree), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack)

**Similar Questions**:
* [Number of Visible People in a Queue (Hard)](https://leetcode.com/problems/number-of-visible-people-in-a-queue)
* [Furthest Building You Can Reach (Medium)](https://leetcode.com/problems/furthest-building-you-can-reach)

**Hints**:
* For each query <code>[x, y]</code>, if <code>x > y</code>, swap <code>x</code> and <code>y</code>. Now, we can assume that <code>x <= y</code>.
* For each query <code>[x, y]</code>, if <code>x == y</code> or <code>heights[x] < heights[y]</code>, then the answer is <code>y</code> since <code>x ≤ y</code>.
* Otherwise, we need to find the smallest index <code>t</code> such that <code>y < t</code> and <code>heights[x] < heights[t]</code>. Note that <code>heights[y] <= heights[x]</code>, so <code>heights[x] < heights[t]</code> is a sufficient condition.
* To find index <code>t</code> for each query, sort the queries in descending order of <code>y</code>. Iterate over the queries while maintaining a monotonic stack which we can binary search over to find index <code>t</code>.

## Solution 1. Offline Query + Monotonic Map

```cpp
// OJ: https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet
// Author: github.com/lzl124631x
// Time: O(H + QlogQ + QlogH)
// Space: O(Q + H)
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& H, vector<vector<int>>& Q) {
        for (int i = 0; i < Q.size(); ++i) {
            if (Q[i][0] > Q[i][1]) swap(Q[i][0], Q[i][1]);
            Q[i].push_back(i);
        }
        sort(begin(Q), end(Q), [](auto &a, auto &b) { return a[1] > b[1]; });
        map<int, int> m; // height -> left most index. Both are monotonically increasing
        vector<int> ans(Q.size(), -1);
        int i = H.size() - 1;
        auto insert = [&](int h, int i) {
            m[h] = i;
            for (auto it = m.begin(); it != m.end() && it->first != h; m.erase(it++)); // delete all the keys < `h`, because they have smaller height with greater index, which won't be better than {h, i}.
        };
        for (auto &q : Q) {
            int a = q[0], b = q[1], idx = q[2];
            if (a == b) {
                ans[idx] = a;
                continue;
            }
            for (; i >= 0 && i >= b; --i) insert(H[i], i);
            int goal = H[a] >= H[b] ? H[a] + 1 : H[b];
            auto it = m.lower_bound(goal);
            if (it != m.end()) ans[idx] = it->second;
        }
        return ans;
    }
};
```