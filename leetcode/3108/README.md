# [3108. Minimum Cost Walk in Weighted Graph (Hard)](https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph)

<p>There is an undirected weighted graph with <code>n</code> vertices labeled from <code>0</code> to <code>n - 1</code>.</p>

<p>You are given the integer <code>n</code> and an array <code>edges</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code> indicates that there is an edge between vertices <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> with a weight of <code>w<sub>i</sub></code>.</p>

<p>A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It&#39;s important to note that a walk may visit the same edge or vertex more than once.</p>

<p>The <strong>cost</strong> of a walk starting at node <code>u</code> and ending at node <code>v</code> is defined as the bitwise <code>AND</code> of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is <code>w<sub>0</sub>, w<sub>1</sub>, w<sub>2</sub>, ..., w<sub>k</sub></code>, then the cost is calculated as <code>w<sub>0</sub> &amp; w<sub>1</sub> &amp; w<sub>2</sub> &amp; ... &amp; w<sub>k</sub></code>, where <code>&amp;</code> denotes the bitwise <code>AND</code> operator.</p>

<p>You are also given a 2D array <code>query</code>, where <code>query[i] = [s<sub>i</sub>, t<sub>i</sub>]</code>. For each query, you need to find the minimum cost of the walk starting at vertex <code>s<sub>i</sub></code> and ending at vertex <code>t<sub>i</sub></code>. If there exists no such walk, the answer is <code>-1</code>.</p>

<p>Return <em>the array </em><code>answer</code><em>, where </em><code>answer[i]</code><em> denotes the <strong>minimum</strong> cost of a walk for query </em><code>i</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,-1]</span></p>

<p><strong>Explanation:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/31/q4_example1-1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 351px; height: 141px;" />
<p>To achieve the cost of 1 in the first query, we need to move on the following edges: <code>0-&gt;1</code> (weight 7), <code>1-&gt;2</code> (weight 1), <code>2-&gt;1</code> (weight 1), <code>1-&gt;3</code> (weight 7).</p>

<p>In the second query, there is no walk between nodes 3 and 4, so the answer is -1.</p>

<p><strong class="example">Example 2:</strong></p>
</div>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0]</span></p>

<p><strong>Explanation:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/31/q4_example2e.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 211px; height: 181px;" />
<p>To achieve the cost of 0 in the first query, we need to move on the following edges: <code>1-&gt;2</code> (weight 1), <code>2-&gt;1</code> (weight 6), <code>1-&gt;2</code> (weight 1).</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= w<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= query.length &lt;= 10<sup>5</sup></code></li>
	<li><code>query[i].length == 2</code></li>
	<li><code>0 &lt;= s<sub>i</sub>, t<sub>i</sub> &lt;= n - 1</code></li>
</ul>

**Hints**:

- The intended solution uses Disjoint Set Union.
- Notice that, if <code>u</code> and <code>v</code> are not connected then the answer is <code>-1</code>, otherwise we can use all the edges from the connected component where both belong to.

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph
// Author: github.com/lzl124631x
// Time: O((E + Q) * logN)
// Space: O(N)
class UnionFind {
    vector<int> id, cost;
public:
    UnionFind(int n) : id(n), cost(n, -1) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b, int w) {
        int x = find(a), y = find(b);
        cost[x] = w & cost[x] & cost[y];
        if (x != y) id[y] = x;
    }
    bool connected(int a, int b) { return find(a) == find(b); }
    int getCost(int a) { return cost[find(a)]; }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<int> ans(Q.size(), -1);
        UnionFind uf(n);
        for (auto &e : E) {
            int u = e[0], v = e[1], w = e[2];
            uf.connect(u, v, w);
        }
        for (int i = 0; i < Q.size(); ++i) {
            auto &q = Q[i];
            int u = q[0], v = q[1];
            if (u == v) ans[i] = 0;
            else if (uf.connected(u, v)) ans[i] = uf.getCost(u);
        }
        return ans;
    }
}
```
