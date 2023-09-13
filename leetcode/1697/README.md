# [1697. Checking Existence of Edge Length Limited Paths (Hard)](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/)

<p>An undirected graph of <code>n</code> nodes is defined by <code>edgeList</code>, where <code>edgeList[i] = [u<sub>i</sub>, v<sub>i</sub>, dis<sub>i</sub>]</code> denotes an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> with distance <code>dis<sub>i</sub></code>. Note that there may be <strong>multiple</strong> edges between two nodes.</p>

<p>Given an array <code>queries</code>, where <code>queries[j] = [p<sub>j</sub>, q<sub>j</sub>, limit<sub>j</sub>]</code>, your task is to determine for each <code>queries[j]</code> whether there is a path between <code>p<sub>j</sub></code> and <code>q<sub>j</sub></code><sub> </sub>such that each edge on the path has a distance <strong>strictly less than</strong> <code>limit<sub>j</sub></code> .</p>

<p>Return <em>a <strong>boolean array</strong> </em><code>answer</code><em>, where </em><code>answer.length == queries.length</code> <em>and the </em><code>j<sup>th</sup></code> <em>value of </em><code>answer</code> <em>is </em><code>true</code><em> if there is a path for </em><code>queries[j]</code><em> is </em><code>true</code><em>, and </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/08/h.png" style="width: 267px; height: 262px;">
<pre><strong>Input:</strong> n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
<strong>Output:</strong> [false,true]
<strong>Explanation:</strong> The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -&gt; 1 -&gt; 2) of two edges with distances less than 5, thus we return true for this query.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/08/q.png" style="width: 390px; height: 358px;">
<pre><strong>Input:</strong> n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
<strong>Output:</strong> [true,false]
<strong>Exaplanation:</strong> The above figure shows the given graph.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= edgeList.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edgeList[i].length == 3</code></li>
	<li><code>queries[j].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub>, p<sub>j</sub>, q<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>p<sub>j</sub> != q<sub>j</sub></code></li>
	<li><code>1 &lt;= dis<sub>i</sub>, limit<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
	<li>There may be <strong>multiple</strong> edges between two nodes.</li>
</ul>


**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Union Find

Sort the edges from small distance to large distance.

Traverse the queries from small limit to large limit. Given a limit, we union the nodes that can be connected.

In this way, we just need to traverse the edges that are smaller than the limit. Since we are visiting the queries with increasing limit, we just need to visit the edges once from small distance to large distance.

```cpp
// OJ: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
// Author: github.com/lzl124631x
// Time: O(ElogE + QlogQ)
// Space: O(N)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<bool> ans(Q.size());
        for (int i = 0; i < Q.size(); ++i) Q[i].push_back(i);
        sort(begin(Q), end(Q), [&](auto &a, auto &b) { return a[2] < b[2]; });
        sort(begin(E), end(E), [&](auto &a, auto &b) { return a[2] < b[2]; });
        UnionFind uf(n);
        int i = 0;
        for (auto &q : Q) { // traverse the queries from small limit to large limit
            int u = q[0], v = q[1], limit = q[2], qid = q[3];
            for (; i < E.size() && E[i][2] < limit; ++i) uf.connect(E[i][0], E[i][1]); // visit the edges that are smaller than the limit
            ans[qid] = uf.connected(u, v);
        }
        return ans;
    }
};
```