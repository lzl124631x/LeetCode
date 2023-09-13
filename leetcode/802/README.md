# [802. Find Eventual Safe States (Medium)](https://leetcode.com/problems/find-eventual-safe-states)

<p>There is a directed graph of <code>n</code> nodes with each node labeled from <code>0</code> to <code>n - 1</code>. The graph is represented by a <strong>0-indexed</strong> 2D integer array <code>graph</code> where <code>graph[i]</code> is an integer array of nodes adjacent to node <code>i</code>, meaning there is an edge from node <code>i</code> to each node in <code>graph[i]</code>.</p>
<p>A node is a <strong>terminal node</strong> if there are no outgoing edges. A node is a <strong>safe node</strong> if every possible path starting from that node leads to a <strong>terminal node</strong> (or another safe node).</p>
<p>Return <em>an array containing all the <strong>safe nodes</strong> of the graph</em>. The answer should be sorted in <strong>ascending</strong> order.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="Illustration of graph" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/17/picture1.png" style="height: 171px; width: 600px;">
<pre><strong>Input:</strong> graph = [[1,2],[2,3],[5],[0],[5],[],[]]
<strong>Output:</strong> [2,4,5,6]
<strong>Explanation:</strong> The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
<strong>Output:</strong> [4]
<strong>Explanation:</strong>
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == graph.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= graph[i].length &lt;= n</code></li>
	<li><code>0 &lt;= graph[i][j] &lt;= n - 1</code></li>
	<li><code>graph[i]</code> is sorted in a strictly increasing order.</li>
	<li>The graph may contain self-loops.</li>
	<li>The number of edges in the graph will be in the range <code>[1, 4 * 10<sup>4</sup>]</code>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Mindtickle](https://leetcode.com/company/mindtickle)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Build a Matrix With Conditions (Hard)](https://leetcode.com/problems/build-a-matrix-with-conditions/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/find-eventual-safe-states
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        int N = G.size();
        vector<int> state(N, -2), ans; // -2 unvisited, -1 visiting, 0 unsafe, 1 safe
        function<bool(int)> dfs = [&](int u) {
            if (state[u] == -1) return state[u] = 0;
            if (state[u] >= 0) return state[u];
            state[u] = -1;
            for (int v : G[u]) {
                if (!dfs(v)) return state[u] = 0;
            }
            return state[u] = 1;
        };
        for (int i = 0; i < N; ++i) {
            if (dfs(i)) ans.push_back(i);
        }
        return ans;
    }
};
```

## Solution 2. Topological Sort (BFS) + Reverse Edges

```cpp
// OJ: https://leetcode.com/problems/find-eventual-safe-states/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        int N = G.size();
        vector<vector<int>> R(N);
        vector<int> outdegree(N), safe(N), ans;
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            for (int v : G[i]) {
                R[v].push_back(i);
            }
            outdegree[i] = G[i].size();
            if (outdegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            safe[u] = 1;
            for (int v : R[u]) {
                if (--outdegree[v] == 0) q.push(v);
            }
        }
        for (int i = 0; i < N; ++i) {
            if (safe[i]) ans.push_back(i);
        }
        return ans;
    }
};
```