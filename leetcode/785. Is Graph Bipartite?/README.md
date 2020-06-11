# [785. Is Graph Bipartite? (Medium)](https://leetcode.com/problems/is-graph-bipartite/)

<p>Given an undirected&nbsp;<code>graph</code>, return <code>true</code> if and only if it is bipartite.</p>

<p>Recall that a graph is <em>bipartite</em> if we can split it's set of nodes into two independent&nbsp;subsets A and B such that every edge in the graph has one node in A and another node in B.</p>

<p>The graph is given in the following form: <code>graph[i]</code> is a list of indexes <code>j</code> for which the edge between nodes <code>i</code> and <code>j</code> exists.&nbsp; Each node is an integer between <code>0</code> and <code>graph.length - 1</code>.&nbsp; There are no self edges or parallel edges: <code>graph[i]</code> does not contain <code>i</code>, and it doesn't contain any element twice.</p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong> [[1,3], [0,2], [1,3], [0,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
</pre>

<pre><strong>Example 2:</strong>
<strong>Input:</strong> [[1,2,3], [0,2], [0,1,3], [0,2]]
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>graph</code> will have length in range <code>[1, 100]</code>.</li>
	<li><code>graph[i]</code> will contain integers in range <code>[0, graph.length - 1]</code>.</li>
	<li><code>graph[i]</code> will not contain <code>i</code> or duplicate values.</li>
	<li>The graph is undirected: if any element <code>j</code> is in <code>graph[i]</code>, then <code>i</code> will be in <code>graph[j]</code>.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    bool dfs(vector<vector<int>> &G, vector<int> &id, int u, int prev = 1) {
        if (id[u]) return id[u] != prev;
        id[u] = -prev;
        for (int v : G[u]) {
            if (!dfs(G, id, v, id[u])) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& G) {
        vector<int> id(G.size());
        for (int i = 0; i < G.size(); ++i) {
            if (id[i]) continue;
            if (!dfs(G, id, i)) return false;
        }
        return true;
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& G) {
        vector<int> id(G.size());
        queue<int> q;
        for (int i = 0; i < G.size(); ++i) {
            if (id[i]) continue;
            q.push(i);
            id[i] = 1;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (id[v]) {
                        if (id[v] != -id[u]) return false;
                        continue;
                    }
                    id[v] = -id[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
};
```