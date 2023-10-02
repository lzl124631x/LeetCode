# [1617. Count Subtrees With Max Distance Between Cities (Hard)](https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/)

<p>There are <code>n</code> cities numbered from <code>1</code> to <code>n</code>. You are given an array <code>edges</code> of size <code>n-1</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> represents a bidirectional edge between cities <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code>. There exists a unique path between each pair of cities. In other words, the cities form a <strong>tree</strong>.</p>

<p>A <strong>subtree</strong> is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.</p>

<p>For each <code>d</code> from <code>1</code> to <code>n-1</code>, find the number of subtrees in which the <strong>maximum distance</strong> between any two cities in the subtree is equal to <code>d</code>.</p>

<p>Return <em>an array of size</em> <code>n-1</code> <em>where the </em><code>d<sup>th</sup></code><em> </em><em>element <strong>(1-indexed)</strong> is the number of subtrees in which the <strong>maximum distance</strong> between any two cities is equal to </em><code>d</code>.</p>

<p><strong>Notice</strong>&nbsp;that&nbsp;the <strong>distance</strong> between the two cities is the number of edges in the path between them.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/p1.png" style="width: 161px; height: 181px;"></strong></p>

<pre><strong>Input:</strong> n = 4, edges = [[1,2],[2,3],[2,4]]
<strong>Output:</strong> [3,4,0]
<strong>Explanation:
</strong>The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
No subtree has two nodes where the max distance between them is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, edges = [[1,2]]
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 3, edges = [[1,2],[2,3]]
<strong>Output:</strong> [2,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 15</code></li>
	<li><code>edges.length == n-1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li>All pairs <code>(u<sub>i</sub>, v<sub>i</sub>)</code> are distinct.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Tree Diameter (Medium)](https://leetcode.com/problems/tree-diameter/)

## Solution 1.

We need to:
* traverse all the subset of nodes. We can use bitmask for this.
* check if the subset is connected. We can use DFS, BFS, UnionFind.
* get the maximum distance of the subtree. We can use Floyd algorithm to precompute the (minimal) distance between every node pairs. And in the subtree, just find the maximum distance by traversing every node pairs.

Time complexity:
* `O(N^3)` for Floyd
* `O(2^N)` for bitmask subset traversal
  * `O(N)` for `memset`, filling `incl`, and `dfs`.
  * `O(N^2)` for getting the maximum distance

So overall the time complexity is `O(2^N * N^2)`.

```cpp
// OJ: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N^2)
class Solution {
    int seen[16] = {}, incl[16] = {}; // incl[i] == 1 if node `i` is included in mask
    vector<int> g[16];
    void dfs(int u, int &cnt) {
        if (!incl[u] || seen[u]) return;
        ++cnt;
        seen[u] = 1;
        for (int v : g[u]) dfs(v, cnt);
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& E) {
        int dist[16][16] = {};
        memset(dist, 0x3f, sizeof(dist));
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].push_back(v);
            g[v].push_back(u);
            dist[u][v] = dist[v][u] = 1;
        }
        for (int k = 0; k < n; ++k) { // use floyd to get the minimal distance between every two nodes.
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int> ans(n - 1);
        for (int mask = 1; mask < (1 << n); ++mask) {
            memset(seen, 0, sizeof(seen));
            memset(incl, 0, sizeof(incl));
            int cnt = __builtin_popcount(mask), start;
            if (cnt < 2) continue;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    incl[i] = 1;
                    start = i;
                }
            }
            int c = 0;
            dfs(start, c); // count how many nodes we can visit.
            if (cnt != c) continue; // not all nodes are connected
            int mx = 0;
            for (int i = 0; i < n; ++i) {
                if (!incl[i]) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (!incl[j]) continue;
                    mx = max(mx, dist[i][j]);
                }
            }
            ++ans[mx - 1];
        }
        return ans;
    }
};
```

## Solution 2.

We can use two DFS to get the tree's diameter and by the way we can know if the subtree is connected by counting the `dist`.

```cpp
// OJ: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(N + E)
class Solution {
    int incl[16] = {}, dist[16] = {}; // incl[i] == 1 if node `i` is included in mask
    vector<int> g[16];
    void dfs(int u, int &far) {
        for (int v : g[u]) {
            if (!incl[v] || dist[v]) continue;
            dist[v] = dist[u] + 1;
            if (dist[v] > dist[far]) far = v;
            dfs(v, far);
        }
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& E) {
        memset(dist, 0x3f, sizeof(dist));
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> ans(n - 1);
        for (int mask = 1; mask < (1 << n); ++mask) {
            int cnt = __builtin_popcount(mask), node, c = 0;
            if (cnt < 2) continue;
            memset(incl, 0, sizeof(incl));
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    incl[i] = 1;
                    node = i;
                }
            }
            memset(dist, 0, sizeof(dist));
            dist[node] = 1;
            dfs(node, node);
            for (int i = 0; i < n; ++i) c += incl[i] && dist[i];
            if (c != cnt) continue;
            memset(dist, 0, sizeof(dist));
            dist[node] = 1;
            dfs(node, node);
            ++ans[dist[node] - 2];
        }
        return ans;
    }
};
```