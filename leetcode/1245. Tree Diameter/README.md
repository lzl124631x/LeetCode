# [1245. Tree Diameter (Medium)](https://leetcode.com/problems/tree-diameter/)

<p>Given an undirected tree, return&nbsp;its diameter: the number of <strong>edges</strong> in a longest path in that tree.</p>

<p>The tree is given as an array&nbsp;of&nbsp;<code>edges</code>&nbsp;where <code>edges[i] = [u, v]</code> is a bidirectional edge between nodes&nbsp;<code>u</code> and <code>v</code>.&nbsp; Each node has&nbsp;labels in the set <code>{0, 1, ..., edges.length}</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/06/14/1397_example_1.PNG" style="width: 226px; height: 233px;"></p>

<pre><strong>Input:</strong> edges = [[0,1],[0,2]]
<strong>Output:</strong> 2
<strong>Explanation: </strong>
A longest path of the tree is the path 1 - 0 - 2.
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/06/14/1397_example_2.PNG" style="width: 350px; height: 316px;"></p>

<pre><strong>Input:</strong> edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= edges.length &lt;&nbsp;10^4</code></li>
	<li><code>edges[i][0] != edges[i][1]</code></li>
	<li><code>0 &lt;= edges[i][j] &lt;= edges.length</code></li>
	<li>The given edges form an undirected tree.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Count Subtrees With Max Distance Between Cities (Hard)](https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/)

## Solution 1. BFS Topological Sort

```cpp
// OJ: https://leetcode.com/problems/tree-diameter/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int treeDiameter(vector<vector<int>>& E) {
        int N = E.size() + 1, step = 0;
        vector<vector<int>> G(N);
        vector<int> indegree(N);
        for (auto &e : E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 1) q.push(i);
        }
        while (q.size() > 1) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                --indegree[u];
                for (int v : G[u]) {
                    if (indegree[v] == 0) continue;
                    if (--indegree[v] == 1) {
                        q.push(v);
                    }
                }
            }
            ++step;
        }
        return step * 2 + q.size() - 1;
    }
};
```

## Solution 2. Find the furthest node twice

The BFS Version:

```cpp
// OJ: https://leetcode.com/problems/tree-diameter/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> G;
    vector<int> dist;
    int N;
    int furthest(int start) {
        queue<int> q{{start}};
        dist.assign(N + 1, INT_MAX);
        dist[start] = 0;
        int ans = 0, step = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                ans = u;
                for (int v : G[u]) {
                    if (dist[v] != INT_MAX) continue;
                    dist[v] = step + 1;
                    q.push(v);
                }
            }
            ++step;
        }
        return ans;
    }
public:
    int treeDiameter(vector<vector<int>>& E) {
        N = E.size() + 1;
        G.assign(N, {});
        for (auto &e : E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        return dist[furthest(furthest(0))];
    }
};
```

The DFS Version:

```cpp
// OJ: https://leetcode.com/problems/tree-diameter/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> G;
    vector<int> dist;
    int N;
    int dfs(int u, int level = 0) {
        if (dist[u] != INT_MAX) return u;
        dist[u] = level;
        int ans = u;
        for (int v : G[u]) {
            int f = dfs(v, level + 1);
            if (dist[f] > dist[ans]) ans = f;
        }
        return ans;
    }
    int furthest(int start, int level = 0) {
        dist.assign(N, INT_MAX);
        return dfs(start);
    }
public:
    int treeDiameter(vector<vector<int>>& E) {
        N = E.size() + 1;
        G.assign(N, {});
        for (auto &e : E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        return dist[furthest(furthest(0))];
    }
};
```

## Solution 3. DFS

```cpp
// OJ: https://leetcode.com/problems/tree-diameter/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/tree-diameter/solution/
class Solution {
    vector<vector<int>> G;
    int N, ans = 0;
    vector<bool> seen;
    int dfs(int u) {
        seen[u] = true;
        int first = 0, second = 0;
        for (int v : G[u]) {
            if (seen[v]) continue;
            int d = 1 + dfs(v);
            if (d > first) {
                second = first;
                first = d;
            } else if (d > second) second = d;
        }
        ans = max(ans, first + second);
        return first;
    }
public:
    int treeDiameter(vector<vector<int>>& E) {
        N = E.size() + 1;
        G.assign(N, {});
        seen.assign(N, false);
        for (auto &e : E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        dfs(0);
        return ans;
    }
};
```