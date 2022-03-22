# [1786. Number of Restricted Paths From First to Last Node (Medium)](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/)

<p>There is an undirected weighted connected graph. You are given a positive integer <code>n</code> which denotes that the graph has <code>n</code> nodes labeled from <code>1</code> to <code>n</code>, and an array <code>edges</code> where each <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, weight<sub>i</sub>]</code> denotes that there is an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> with weight equal to <code>weight<sub>i</sub></code>.</p>

<p>A path from node <code>start</code> to node <code>end</code> is a sequence of nodes <code>[z<sub>0</sub>, z<sub>1</sub>,<sub> </sub>z<sub>2</sub>, ..., z<sub>k</sub>]</code> such that <code>z<sub>0 </sub>= start</code> and <code>z<sub>k</sub> = end</code> and there is an edge between <code>z<sub>i</sub></code> and <code>z<sub>i+1</sub></code> where <code>0 &lt;= i &lt;= k-1</code>.</p>

<p>The distance of a path is the sum of the weights on the edges of the path. Let <code>distanceToLastNode(x)</code> denote the shortest distance of a path between node <code>n</code> and node <code>x</code>. A <strong>restricted path</strong> is a path that also satisfies that <code>distanceToLastNode(z<sub>i</sub>) &gt; distanceToLastNode(z<sub>i+1</sub>)</code> where <code>0 &lt;= i &lt;= k-1</code>.</p>

<p>Return <em>the number of restricted paths from node</em> <code>1</code> <em>to node</em> <code>n</code>. Since that number may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/17/restricted_paths_ex1.png" style="width: 351px; height: 341px;">
<pre><strong>Input:</strong> n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Each circle contains the node number in black and its <code>distanceToLastNode value in blue. </code>The three restricted paths are:
1) 1 --&gt; 2 --&gt; 5
2) 1 --&gt; 2 --&gt; 3 --&gt; 5
3) 1 --&gt; 3 --&gt; 5
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/17/restricted_paths_ex22.png" style="width: 356px; height: 401px;">
<pre><strong>Input:</strong> n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Each circle contains the node number in black and its <code>distanceToLastNode value in blue. </code>The only restricted path is 1 --&gt; 3 --&gt; 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>n - 1 &lt;= edges.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li><code>1 &lt;= weight<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li>There is at most one edge between any two nodes.</li>
	<li>There is at least one path between any two nodes.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [All Ancestors of a Node in a Directed Acyclic Graph (Medium)](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)

## Solution 1. Dijkstra + DP

We run Dijkstra algorithm starting from the `n`th node. 

Let `dist[u]` be the distance from the `u` node to `n`th node.

Let `cnt[u]` be the number of restricted path from `u` node to `n`th node.

Each time we visit a new node `u`, we can update its `cnt[u]` to be the sum of `cnt[v]` where `v` is a neighbor of `u` and `dist[v]` is smaller than `dist[u]`.

The answer is `cnt[0]`.

```cpp
// OJ: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
// Author: github.com/lzl124631x
// Time: O(ElogE)
// Space: O(E)
class Solution {
    typedef pair<int, int> PII;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& E) {
        long mod = 1e9 + 7;
        vector<vector<PII>> G(n);
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<long> dist(n, INT_MAX), cnt(n, 0);
        dist[n - 1] = 0;
        cnt[n - 1] = 1;
        pq.emplace(0, n - 1);
        while (pq.size()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost > dist[u]) continue;
            for (auto &[v, w] : G[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.emplace(dist[v], v);
                }
                if (cost > dist[v]) cnt[u] = (cnt[u] + cnt[v]) % mod;
            }
        }
        return cnt[0];
    }
};
```