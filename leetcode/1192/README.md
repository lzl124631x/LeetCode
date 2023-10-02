# [1192. Critical Connections in a Network (Hard)](https://leetcode.com/problems/critical-connections-in-a-network/)

<p>There are <code>n</code> servers numbered from <code>0</code> to <code>n - 1</code> connected by undirected server-to-server <code>connections</code> forming a network where <code>connections[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> represents a connection between servers <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>. Any server can reach other servers directly or indirectly through the network.</p>

<p>A <em>critical connection</em> is a connection that, if removed, will make some servers unable to reach some other server.</p>

<p>Return all critical connections in the network in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png" style="width: 198px; height: 248px;">
<pre><strong>Input:</strong> n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
<strong>Output:</strong> [[1,3]]
<strong>Explanation:</strong> [[3,1]] is also accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, connections = [[0,1]]
<strong>Output:</strong> [[0,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n - 1 &lt;= connections.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated connections.</li>
</ul>


**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Biconnected Component](https://leetcode.com/tag/biconnected-component/)

## Solution 1.

An edge is a critical connection, if and only if it is not in a cycle.

So we need to find the cycles and discard all edges in them. The remaining connections are those critical.

Here we use DFS + ranks. `ranks[u]` is the depth of a node during DFS. The starting node has a rank `0`.

`ranks` are initialized as `-INF` meaning that the nodes are unvisited. A valid rank value is in `[0, n)`.

When we do DFS on node `u` and we see a neighbor `v` that has `ranks[v] != -INF` and `rank[v] < rank[u] - 1`, we know that `v` is an ancestor node of `u` and `uv` is on a cicle.

But only the current level of search knows it finds a cycle. To let upper levels of search know, we make use of the return value of DFS: `dfs` function returns the minimum rank it finds. During a step of search from node `u` to its neighbor `v`, if `dfs(v)` returns something smaller than or equal to `ranks[u]`, then `u` knows its neighbor `v` helped it to find a cycle back to `u` or `u`'s ancestor. So `u` knows it should discard the edge `uv` which is in a cycle.

```cpp
// OJ: https://leetcode.com/problems/critical-connections-in-a-network/
// Author: github.com/lzl124631x
// Time: O(V+E), since this is a connected graph, E >= V-1, so here `O(V+E) == O(E)`.
// Space: O(E)
// Ref: https://leetcode.com/problems/critical-connections-in-a-network/discuss/382638/DFS-detailed-explanation-O(orEor)-solution
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& E) {
        vector<int> ranks(n, INT_MIN); // INT_MIN unvisited, 0~n-1 rank values
        vector<vector<int>> G(n), ans;
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        function<int(int, int)> dfs = [&](int u, int rank) {
            if (ranks[u] >= 0) return ranks[u];
            ranks[u] = rank;
            int minRank = rank;
            for (int v : G[u]) {
                // The relationship between `ranks[v]` and `rank` only has the following cases:
                // 1. ranks[v] == rank - 1: `v` is visited and is the direct parent node of `u` in the DFS path.
                // 2. ranks[v] > rank: `v` has been visited and is a child of `u`. There exists a circle containing edge `uv`. Since `v` is already visited, we don't want to visit it again
                // 3. ranks[v] < rank - 1: There are two subcases
                //    3.1. ranks[v] == -INF. `v` is not visited.
                //    3.2. ranks[v] != -INF && ranks[v] < rank - 1: `v` is an ancestor node of `u`, so `uv` is on a circle.
                // Note that `ranks[v] == rank` is impossible.
                if (ranks[v] >= rank - 1) continue;
                int neighborMinRank = dfs(v, rank + 1);
                minRank = min(minRank, neighborMinRank);
                if (neighborMinRank > rank) ans.push_back({u, v}); // if neightborRank > rank, this edge `uv` is not on any circle -- it's a critical path
            }
            return minRank;
        };
        dfs(0, 0);
        return ans;
    }
};
```