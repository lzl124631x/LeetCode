# [685. Redundant Connection II (Hard)](https://leetcode.com/problems/redundant-connection-ii/)

<p>In this problem, a rooted tree is a <b>directed</b> graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.</p>

<p>The given input is a directed graph that started as a rooted tree with <code>n</code> nodes (with distinct values from <code>1</code> to <code>n</code>), with one additional directed edge added. The added edge has two different vertices chosen from <code>1</code> to <code>n</code>, and was not an edge that already existed.</p>

<p>The resulting graph is given as a 2D-array of <code>edges</code>. Each element of <code>edges</code> is a pair <code>[u<sub>i</sub>, v<sub>i</sub>]</code> that represents a <b>directed</b> edge connecting nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code>, where <code>u<sub>i</sub></code> is a parent of child <code>v<sub>i</sub></code>.</p>

<p>Return <em>an edge that can be removed so that the resulting graph is a rooted tree of</em> <code>n</code> <em>nodes</em>. If there are multiple answers, return the answer that occurs last in the given 2D-array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/graph1.jpg" style="width: 222px; height: 222px;">
<pre><strong>Input:</strong> edges = [[1,2],[1,3],[2,3]]
<strong>Output:</strong> [2,3]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/graph2.jpg" style="width: 222px; height: 382px;">
<pre><strong>Input:</strong> edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
<strong>Output:</strong> [4,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Redundant Connection (Medium)](https://leetcode.com/problems/redundant-connection/)

## Solution 1.

If a node has indegree 2:
* If there is a cycle in the graph, delete the edge pointing to this node within the cycle. (case 1)
* If there is no cycle, delete the edge with greater index. (case 2)
Otherwise there must be a cycle in the graph, delete an edge in the cycle with the greatest index (case 3)

NOTE: this solution is too complicated. Need to find better solution in Discuss.

```cpp
// OJ: https://leetcode.com/problems/redundant-connection-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& E) {
        int N = E.size(), terminal = -1;
        vector<vector<pair<int, int>>> G(N);
        vector<vector<pair<int, int>>> R(N);
        vector<bool> onCycle(N, true);
        vector<int> indegree(N), outdegree(N);
        for (int i = 0; i < N; ++i) {
            int u = E[i][0] - 1, v = E[i][1] - 1;
            G[u].push_back({v,i});
            R[v].push_back({u,i});
            if (++indegree[v] == 2) terminal = v;
            ++outdegree[u];
        }
        auto hasCycle = [&]() { // Topological sort to see if there is any cycle in the graph
            queue<int> q;
            int seen = 0;
            for (int i = 0; i < N; ++i) {
                if (indegree[i] == 0) q.push(i);
            }
            while (q.size()) {
                int u = q.front();
                onCycle[u] = false;
                ++seen;
                q.pop();
                for (auto &[v, i] : G[u]) {
                    if (--indegree[v] == 0) q.push(v);
                }
            }
            return seen < N;
        };
        if (hasCycle()) {
            if (terminal != -1) { // case 1
                int a = R[terminal][0].first, b = R[terminal][1].first;
                if (onCycle[a]) return {a + 1, terminal + 1};
                return {b + 1, terminal + 1};
            }
            queue<int> q; // case 3
            for (int i = 0; i < N; ++i) {
                if (outdegree[i] == 0) q.push(i);
            }
            while (q.size()) {
                int u = q.front();
                q.pop();
                onCycle[u] = false; // Topological Sort on the reversed graph to remove nodes that are not on the cycle.
                for (auto &[v, i] : R[u]) {
                    if (--outdegree[v] == 0) q.push(v);
                }
            }
            int ans = -1;
            for (int i = 0; i < N; ++i) {
                if (!onCycle[i]) continue;
                for (auto &[v, j] : R[i]) {
                    ans = max(ans, j); // Find the greatest edge index on the cycle
                }
            }
            return E[ans];
        }
        return {R[terminal][1].first + 1, terminal + 1}; // case 2
    }
};
```