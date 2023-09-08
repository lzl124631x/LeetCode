# [2360. Longest Cycle in a Graph (Hard)](https://leetcode.com/problems/longest-cycle-in-a-graph)

<p>You are given a <strong>directed</strong> graph of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>, where each node has <strong>at most one</strong> outgoing edge.</p>
<p>The graph is represented with a given <strong>0-indexed</strong> array <code>edges</code> of size <code>n</code>, indicating that there is a directed edge from node <code>i</code> to node <code>edges[i]</code>. If there is no outgoing edge from node <code>i</code>, then <code>edges[i] == -1</code>.</p>
<p>Return <em>the length of the <strong>longest</strong> cycle in the graph</em>. If no cycle exists, return <code>-1</code>.</p>
<p>A cycle is a path that starts and ends at the <strong>same</strong> node.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png" style="width: 335px; height: 191px;">
<pre><strong>Input:</strong> edges = [3,3,4,2,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest cycle in the graph is the cycle: 2 -&gt; 4 -&gt; 3 -&gt; 2.
The length of this cycle is 3, so 3 is returned.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-1.png" style="width: 171px; height: 161px;">
<pre><strong>Input:</strong> edges = [2,-1,3,1]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no cycles in this graph.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
</ul>

**Companies**:
[Juspay](https://leetcode.com/company/juspay), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Strange Printer II (Hard)](https://leetcode.com/problems/strange-printer-ii/)
* [Minimum Number of Operations to Sort a Binary Tree by Level (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/)
* [Shortest Cycle in a Graph (Hard)](https://leetcode.com/problems/shortest-cycle-in-a-graph/)

## Solution 1.

* Similar to topological sort, keep removing nodes with 0 indegrees.
* For the remaining nodes, DFS to get the depth

```cpp
// OJ: https://leetcode.com/problems/longest-cycle-in-a-graph
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestCycle(vector<int>& E) {
        int N = E.size(), ans = -1;
        vector<int> indegree(N), depth(N);
        for (int i = 0; i < N; ++i) {
            if (E[i] == -1) continue;
            indegree[E[i]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            depth[u] = -1; // depth[u] == -1 means that this node u is not in a cycle.
            if (E[u] != -1 && --indegree[E[u]] == 0) q.push(E[u]);
        }
        function<int(int, int)> dfs = [&](int i, int d) {
            if (depth[i] == -1) return -1; 
            depth[i] = d;
            if (depth[E[i]]) return depth[i];
            return depth[i] = dfs(E[i], 1 + d);
        };
        for (int i = 0; i < N; ++i) {
            ans = max(ans, dfs(i, 1));
        }
        return ans;
    }
};
```