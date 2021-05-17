# [802. Find Eventual Safe States (Medium)](https://leetcode.com/problems/find-eventual-safe-states/)

<p>In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.&nbsp; If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.</p>

<p>Now, say our starting node is <em>eventually safe&nbsp;</em>if and only if we must eventually walk to a terminal node.&nbsp; More specifically, there exists a natural number <code>K</code> so that for any choice of where to walk, we must have stopped at a terminal node in less than <code>K</code> steps.</p>

<p>Which nodes are eventually safe?&nbsp; Return them as an array in sorted order.</p>

<p>The directed graph has <code>N</code> nodes with labels <code>0, 1, ..., N-1</code>, where <code>N</code> is the length of <code>graph</code>.&nbsp; The&nbsp;graph is given in the following form: <code>graph[i]</code> is a list of labels <code>j</code> such that <code>(i, j)</code> is a directed edge of the graph.</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> graph = [[1,2],[2,3],[5],[0],[5],[],[]]
<strong>Output:</strong> [2,4,5,6]
Here is a diagram of the above graph.

</pre>

<p><img alt="Illustration of graph" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/17/picture1.png" style="height:86px; width:300px"></p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>graph</code> will have length at most <code>10000</code>.</li>
	<li>The number of edges in the graph will not exceed <code>32000</code>.</li>
	<li>Each <code>graph[i]</code> will be a sorted list of different integers, chosen within the range <code>[0, graph.length - 1]</code>.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. Topological Sort (DFS)

```cpp
// OJ: https://leetcode.com/problems/find-eventual-safe-states/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<int> state; // -1 unvisited, 0 visiting, 1 safe, 2 unsafe
    int dfs(vector<vector<int>> &G, int u) {
        if (state[u] == 0) return state[u] = 2; // circle detected, unsafe
        if (state[u] == 1 || state[u] == 2) return state[u];
        state[u] = 0;
        for (int v : G[u]) {
            if (dfs(G, v) == 2) return state[u] = 2; // upstream of unsafe node is unsafe
        }
        return state[u] = 1;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        state.assign(G.size(), -1);
        vector<int> ans;
        for (int i = 0; i < G.size(); ++i) {
            dfs(G, i);
            if (state[i] == 1) ans.push_back(i);
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