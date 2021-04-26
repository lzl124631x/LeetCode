# [1192. Critical Connections in a Network (Hard)](https://leetcode.com/problems/critical-connections-in-a-network/)

<p>There are&nbsp;<code>n</code> servers numbered from&nbsp;<code>0</code>&nbsp;to&nbsp;<code>n-1</code> connected by&nbsp;undirected server-to-server <code>connections</code> forming a network where <code>connections[i] = [a, b]</code>&nbsp;represents a connection between servers <code>a</code>&nbsp;and <code>b</code>. Any server can reach any other server directly or indirectly through the network.</p>

<p>A <em>critical connection</em>&nbsp;is a connection that, if removed, will make some server unable to reach some other server.</p>

<p>Return all critical connections in the network in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png" style="width: 198px; height: 248px;"></strong></p>

<pre><strong>Input:</strong> n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
<strong>Output:</strong> [[1,3]]
<strong>Explanation:</strong> [[3,1]] is also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>n-1 &lt;= connections.length &lt;= 10^5</code></li>
	<li><code>connections[i][0] != connections[i][1]</code></li>
	<li>There are no repeated connections.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/critical-connections-in-a-network/
// Author: github.com/lzl124631x
// Time: O(V+E), since this is a connected graph, E >= V-1, so here `O(V+E) == O(E)`.
// Space: O(E)
// Ref: https://leetcode.com/problems/critical-connections-in-a-network/discuss/382638/DFS-detailed-explanation-O(orEor)-solution
class Solution {
public:
    vector<vector<int>> G, ans;
    vector<int> ranks;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& E) {
        G.resize(n);
        for (auto& e : E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        ranks.resize(n, INT_MIN); // INT_MIN means unvisited
        dfs(0, 0);        
        return ans;
    }
    int dfs(int u, int rank) {
        if (ranks[u] >= 0) return ranks[u];
        ranks[u] = rank;
        int minRank = rank;
        for (auto v : G[u]) {
            // The relationship between `ranks[v]` and `rank` only has the following cases:
            // 1. ranks[v] == rank - 1: `v` is visited and is the direct parent node of `u` in the DFS path.
            // 2. ranks[v] > rank: `v` has been visited and is a child of `u`. There exists a circle containing edge `uv`. Since `v` is already visited, we don't want to visit it again
            // 3. ranks[v] < rank - 1: There are two subcases
            //    3.1. ranks[v] == -INF. `v` is not visited.
            //    3.2. ranks[v] != -INF && ranks[v] < rank - 1: `v` is a ancestor node of `u`, so `uv` is on a circle.
            // Note that `ranks[v] == rank` is impossible.
            if (ranks[v] == rank - 1 || ranks[v] > rank) continue; 
            int neighborRank = dfs(v, rank + 1);
            minRank = min(minRank, neighborRank);
            if (neighborRank > rank) ans.push_back({u, v}); // if neightborRank > rank, this edge `uv` is not on any circle -- it's a critical path
        }
        return minRank;
    }
};
```