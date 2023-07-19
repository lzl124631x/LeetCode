# [261. Graph Valid Tree (Medium)](https://leetcode.com/problems/graph-valid-tree)

<p>You have a graph of <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>. You are given an integer n and a list of <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an undirected edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the graph.</p>
<p>Return <code>true</code> <em>if the edges of the given graph make up a valid tree, and</em> <code>false</code> <em>otherwise</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/tree1-graph.jpg" style="width: 222px; height: 302px;">
<pre><strong>Input:</strong> n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
<strong>Output:</strong> true
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/tree2-graph.jpg" style="width: 382px; height: 222px;">
<pre><strong>Input:</strong> n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>0 &lt;= edges.length &lt;= 5000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no self-loops or repeated edges.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [Number of Connected Components in an Undirected Graph (Medium)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
* [Keys and Rooms (Medium)](https://leetcode.com/problems/keys-and-rooms/)

## Solution 1. Union Find

* No cycle
* Single graph component

```cpp
// OJ: https://leetcode.com/problems/graph-valid-tree/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int N) : id(N), cnt(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
        --cnt;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& E) {
        UnionFind uf(n);
        for (auto &e : E) {
            if (uf.connected(e[0], e[1])) return false;
            uf.connect(e[0], e[1]);
        }
        return uf.getCount() == 1;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/graph-valid-tree/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& E) {
        if (E.size() != n - 1) return false;
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> state(n, -1); // -1 unvisited, 0 visiting, 1 visited
        function<bool(int, int)> dfs = [&](int u, int prev) { // returns true if there is no cycle starting from this node u.
            if (state[u] != -1) return state[u] == 1;
            state[u] = 0;
            for (int v : G[u]) {
                if (v == prev) continue;
                if (!dfs(v, u)) return false;
            }
            state[u] = 1;
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (!dfs(i, -1)) return false;
        }
        return true;
    }
};
```

## Solution 3. BFS

Starting from a random node, `0` for example:
* Can visit `n` nodes
* No cycle

```cpp
// OJ: https://leetcode.com/problems/graph-valid-tree/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n);
        for (auto &e : E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        vector<int> depth(n); // depth starts from 1. Depth 0 means unvisited
        int level = 1, total = 0;
        queue<int> q{{0}};
        while (q.size()) {
            int cnt = q.size();
            total += cnt;
            while (cnt--) {
                int u = q.front();
                q.pop();
                depth[u] = level;
                for (int v : G[u]) {
                    if (depth[v] == depth[u]) return false;
                    if (depth[v] == 0) q.push(v);
                }
            }
            ++level;
        }
        return total == n;
    }
};
```

## Solution 4. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/graph-valid-tree
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& E) {
        if (E.size() != n - 1) return false;
        if (n == 1) return true;
        vector<vector<int>> G(n);
        vector<int> degree(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
            ++degree[u];
            ++degree[v];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            --degree[u];
            --n;
            for (int v : G[u]) {
                if (--degree[v] == 1) q.push(v);
            }
        }
        return n == 0;
    }
};
```