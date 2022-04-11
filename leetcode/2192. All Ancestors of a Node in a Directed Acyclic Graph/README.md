# [2192. All Ancestors of a Node in a Directed Acyclic Graph (Medium)](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)

<p>You are given a positive integer <code>n</code> representing the number of nodes of a <strong>Directed Acyclic Graph</strong> (DAG). The nodes are numbered from <code>0</code> to <code>n - 1</code> (<strong>inclusive</strong>).</p>

<p>You are also given a 2D integer array <code>edges</code>, where <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code> denotes that there is a <strong>unidirectional</strong> edge from <code>from<sub>i</sub></code> to <code>to<sub>i</sub></code> in the graph.</p>

<p>Return <em>a list</em> <code>answer</code><em>, where </em><code>answer[i]</code><em> is the <strong>list of ancestors</strong> of the</em> <code>i<sup>th</sup></code> <em>node, sorted in <strong>ascending order</strong></em>.</p>

<p>A node <code>u</code> is an <strong>ancestor</strong> of another node <code>v</code> if <code>u</code> can reach <code>v</code> via a set of edges.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/12/e1.png" style="width: 322px; height: 265px;">
<pre><strong>Input:</strong> n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
<strong>Output:</strong> [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
<strong>Explanation:</strong>
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/12/e2.png" style="width: 343px; height: 299px;">
<pre><strong>Input:</strong> n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<strong>Output:</strong> [[],[0],[0,1],[0,1,2],[0,1,2,3]]
<strong>Explanation:</strong>
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= edges.length &lt;= min(2000, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li>There are no duplicate edges.</li>
	<li>The graph is <strong>directed</strong> and <strong>acyclic</strong>.</li>
</ul>


**Companies**:  
[Oracle](https://leetcode.com/company/oracle), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Number of Restricted Paths From First to Last Node (Medium)](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n), ans(n);
        bool connect[1001][1001] = {};
        for (auto &e : E) G[e[0]].push_back(e[1]);
        function<void(int, int)> dfs = [&](int u, int s) {
            if (connect[s][u]) return; // If `s` has been added as a source node of `u` already, skip
            connect[s][u] = true;
            for (int v : G[u]) dfs(v, s);
        };
        for (int i = 0; i < n; ++i) dfs(i, i);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && connect[i][j]) ans[j].push_back(i);
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(E)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n), ans(n);
        for (auto &e : E) G[e[0]].push_back(e[1]);
        function<void(int, int)> dfs = [&](int u, int s) {
            for (int v : G[u]) {
                if (ans[v].size() && ans[v].back() == s) continue;
                ans[v].push_back(s);
                dfs(v, s);
            }
        };
        for (int i = 0; i < n; ++i) dfs(i, i);
        return ans;
    }
};
```