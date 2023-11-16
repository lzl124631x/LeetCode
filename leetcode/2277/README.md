# [2277. Closest Node to Path in Tree (Hard)](https://leetcode.com/problems/closest-node-to-path-in-tree)

<p>You are given a positive integer <code>n</code> representing the number of nodes in a tree, numbered from <code>0</code> to <code>n - 1</code> (<strong>inclusive</strong>). You are also given a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [node1<sub>i</sub>, node2<sub>i</sub>]</code> denotes that there is a <strong>bidirectional</strong> edge connecting <code>node1<sub>i</sub></code> and <code>node2<sub>i</sub></code> in the tree.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>query</code> of length <code>m</code> where <code>query[i] = [start<sub>i</sub>, end<sub>i</sub>, node<sub>i</sub>]</code> means that for the <code>i<sup>th</sup></code> query, you are tasked with finding the node on the path from <code>start<sub>i</sub></code> to <code>end<sub>i</sub></code> that is <strong>closest</strong> to <code>node<sub>i</sub></code>.</p>

<p>Return <em>an integer array </em><code>answer</code><em> of length </em><code>m</code><em>, where </em><code>answer[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/05/14/image-20220514132158-1.png" style="width: 300px; height: 211px;" />
<pre>
<strong>Input:</strong> n = 7, edges = [[0,1],[0,2],[0,3],[1,4],[2,5],[2,6]], query = [[5,3,4],[5,3,6]]
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong>
The path from node 5 to node 3 consists of the nodes 5, 2, 0, and 3.
The distance between node 4 and node 0 is 2.
Node 0 is the node on the path closest to node 4, so the answer to the first query is 0.
The distance between node 6 and node 2 is 1.
Node 2 is the node on the path closest to node 6, so the answer to the second query is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/05/14/image-20220514132318-2.png" style="width: 300px; height: 89px;" />
<pre>
<strong>Input:</strong> n = 3, edges = [[0,1],[1,2]], query = [[0,1,2]]
<strong>Output:</strong> [1]
<strong>Explanation:</strong>
The path from node 0 to node 1 consists of the nodes 0, 1.
The distance between node 2 and node 1 is 1.
Node 1 is the node on the path closest to node 2, so the answer to the first query is 1.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/05/14/image-20220514132333-3.png" style="width: 300px; height: 89px;" />
<pre>
<strong>Input:</strong> n = 3, edges = [[0,1],[1,2]], query = [[0,0,0]]
<strong>Output:</strong> [0]
<strong>Explanation:</strong>
The path from node 0 to node 0 consists of the node 0.
Since 0 is the only node on the path, the answer to the first query is 0.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= node1<sub>i</sub>, node2<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>node1<sub>i</sub> != node2<sub>i</sub></code></li>
	<li><code>1 &lt;= query.length &lt;= 1000</code></li>
	<li><code>query[i].length == 3</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub>, node<sub>i</sub> &lt;= n - 1</code></li>
	<li>The graph is a tree.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search)

**Similar Questions**:
* [Count Number of Possible Root Nodes (Hard)](https://leetcode.com/problems/count-number-of-possible-root-nodes)
* [Design Graph With Shortest Path Calculator (Hard)](https://leetcode.com/problems/design-graph-with-shortest-path-calculator)

**Hints**:
* For the ith query, find the distance from node_i to every other node in the tree.
* We can use a BFS to find the distances.
* Use DFS to find all the nodes on the path from start_i to end_i.

## Solution 1. Post-order traversal (Lowest Common Ancestor)

For each query, DFS from `node` to all other nodes. Find the first node (furthest from `node`) that is in both paths to `start` and `end`.

```cpp
// OJ: https://leetcode.com/problems/closest-node-to-path-in-tree
// Author: github.com/lzl124631x
// Time: O(QN)
// Space: O(N)
class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<vector<int>> G(n);
        for (auto &e: E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> ans;
        for (auto &q : Q) {
            int start = q[0], end = q[1], node = q[2], r = -1;
            function<int(int, int)> dfs = [&](int u, int prev) {
                int cnt = 0;
                if (u == start) ++cnt;
                if (u == end) ++cnt;
                for (int v : G[u]) {
                    if (v == prev) continue;
                    cnt += dfs(v, u);
                }
                if (cnt == 2 && r == -1) r = u; // The first node that has both `start` and `end` as children or self is the LCA
                return cnt;
            };
            dfs(node, -1);
            ans.push_back(r);
        }
        return ans;
    }
};
```
Or

```cpp
// OJ: https://leetcode.com/problems/closest-node-to-path-in-tree
// Author: github.com/lzl124631x
// Time: O(QN)
// Space: O(N)
class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> ans;
        for (auto &q : Q) {
            int start = q[0], end = q[1], node = q[2];
            function<int(int, int)> dfs = [&](int u, int prev) {
                int ans = -1;
                if (u == start || u == end) ans = u; // Forward the target node as potential LCA
                for (int v : G[u]) {
                    if (v == prev) continue;
                    int n = dfs(v, u);
                    if (n != -1) {
                        if (ans != -1) ans = u; // Forward the target node or LCA from children to the root
                        else ans = n; // If we've seen two target nodes, the current node is the LCA
                    }
                }
                return ans;
            };
            ans.push_back(dfs(node, -1));
        }
        return ans;
    }
};
```