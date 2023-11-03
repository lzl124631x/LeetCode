# [2359. Find Closest Node to Given Two Nodes (Medium)](https://leetcode.com/problems/find-closest-node-to-given-two-nodes)

<p>You are given a <strong>directed</strong> graph of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>, where each node has <strong>at most one</strong> outgoing edge.</p>

<p>The graph is represented with a given <strong>0-indexed</strong> array <code>edges</code> of size <code>n</code>, indicating that there is a directed edge from node <code>i</code> to node <code>edges[i]</code>. If there is no outgoing edge from <code>i</code>, then <code>edges[i] == -1</code>.</p>

<p>You are also given two integers <code>node1</code> and <code>node2</code>.</p>

<p>Return <em>the <strong>index</strong> of the node that can be reached from both </em><code>node1</code><em> and </em><code>node2</code><em>, such that the <strong>maximum</strong> between the distance from </em><code>node1</code><em> to that node, and from </em><code>node2</code><em> to that node is <strong>minimized</strong></em>. If there are multiple answers, return the node with the <strong>smallest</strong> index, and if no possible answer exists, return <code>-1</code>.</p>

<p>Note that <code>edges</code> may contain cycles.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-2.png" style="width: 321px; height: 161px;" />
<pre>
<strong>Input:</strong> edges = [2,2,3,-1], node1 = 0, node2 = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-4.png" style="width: 195px; height: 161px;" />
<pre>
<strong>Input:</strong> edges = [1,2,-1], node1 = 0, node2 = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
	<li><code>0 &lt;= node1, node2 &lt; n</code></li>
</ul>


**Companies**:
[Juspay](https://leetcode.com/company/juspay)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search), [Graph](https://leetcode.com/tag/graph)

**Hints**:
* How can you find the shortest distance from one node to all nodes in the graph?
* Use BFS to find the shortest distance from both node1 and node2 to all nodes in the graph. Then iterate over all nodes, and find the node with the minimum max distance.

## Solution 1.

* Calculate the distances from node `a` and `b` separately as `da` and `db`.
* Find the node with the min max distance from both nodes

```cpp
// OJ: https://leetcode.com/problems/find-closest-node-to-given-two-nodes
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int closestMeetingNode(vector<int>& E, int a, int b) {
        int N = E.size(), ans = -1, minDist = INT_MAX;
        vector<int> da(N, INT_MAX), db(N, INT_MAX);
        auto updateDist = [&](int u, vector<int> &dist) {
            int lv = 0;
            while (u != -1 && dist[u] == INT_MAX) {
                dist[u] = lv++;
                u = E[u];
            }
        };
        updateDist(a, da);
        updateDist(b, db);
        for (int i = 0; i < N; ++i) {
            int d = max(da[i], db[i]);
            if (d < minDist) {
                minDist = d;
                ans = i;
            }
        }
        return ans;
    }
};
```