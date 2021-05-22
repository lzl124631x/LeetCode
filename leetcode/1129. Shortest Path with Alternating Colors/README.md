# [1129. Shortest Path with Alternating Colors (Medium)](https://leetcode.com/problems/shortest-path-with-alternating-colors/)

<p>Consider a directed graph, with nodes labelled <code>0, 1, ..., n-1</code>.&nbsp; In this graph, each edge is either red or blue, and there could&nbsp;be self-edges or parallel edges.</p>

<p>Each <code>[i, j]</code> in <code>red_edges</code> denotes a red directed edge from node <code>i</code> to node <code>j</code>.&nbsp; Similarly, each <code>[i, j]</code> in <code>blue_edges</code> denotes a blue directed edge from node <code>i</code> to node <code>j</code>.</p>

<p>Return an array <code>answer</code>&nbsp;of length <code>n</code>,&nbsp;where each&nbsp;<code>answer[X]</code>&nbsp;is&nbsp;the length of the shortest path from node <code>0</code>&nbsp;to node <code>X</code>&nbsp;such that the edge colors alternate along the path (or <code>-1</code> if such a path doesn't exist).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
<strong>Output:</strong> [0,1,-1]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
<strong>Output:</strong> [0,1,-1]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
<strong>Output:</strong> [0,-1,-1]
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
<strong>Output:</strong> [0,1,2]
</pre><p><strong>Example 5:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
<strong>Output:</strong> [0,1,1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>red_edges.length &lt;= 400</code></li>
	<li><code>blue_edges.length &lt;= 400</code></li>
	<li><code>red_edges[i].length == blue_edges[i].length == 2</code></li>
	<li><code>0 &lt;= red_edges[i][j], blue_edges[i][j] &lt; n</code></li>
</ul>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Wish](https://leetcode.com/company/wish)

**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-path-with-alternating-colors/
// Author: github.com/lzl124631x
// Time: O(R + B + N^2)
// Space: O(N^2)
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& R, vector<vector<int>>& B) {
        vector<int> a(n, -1), b(n, -1), ans(n, -1);
        a[0] = b[0] = ans[0] = 0;
        int G[100][100] = {};
        for (auto &r : R) G[r[0]][r[1]] = 1;
        for (auto &b : B) G[b[0]][b[1]] |= 2;
        queue<pair<int, int>> q;
        q.emplace(0, 3);
        int step = 1;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [u, color] = q.front();
                q.pop();
                for (int v = 0; v < n; ++v) {
                    if (a[v] == -1 && (G[u][v] & 1) && (color & 2)) {
                        q.emplace(v, 1);
                        a[v] = step;
                        ans[v] = ans[v] == -1 ? a[v] : min(a[v], ans[v]);
                    }
                    if (b[v] == -1 && (G[u][v] & 2) && (color & 1)) {
                        q.emplace(v, 2);
                        b[v] = step;
                        ans[v] = ans[v] == -1 ? b[v] : min(b[v], ans[v]);
                    }
                }
            }
            ++step;
        }
        return ans;
    }
};
```