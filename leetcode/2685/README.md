# [2685. Count the Number of Complete Components (Medium)](https://leetcode.com/problems/count-the-number-of-complete-components)

<p>You are given an integer <code>n</code>. There is an <strong>undirected</strong> graph with <code>n</code> vertices, numbered from <code>0</code> to <code>n - 1</code>. You are given a 2D integer array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists an <strong>undirected</strong> edge connecting vertices <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>
<p>Return <em>the number of <strong>complete connected components</strong> of the graph</em>.</p>
<p>A <strong>connected component</strong> is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.</p>
<p>A connected component is said to be <b>complete</b> if there exists an edge between every pair of its vertices.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-31-23.png" style="width: 671px; height: 270px;"></strong></p>
<pre><strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the picture above, one can see that all of the components of this graph are complete.
</pre>
<p><strong class="example">Example 2:</strong></p>
<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-32-00.png" style="width: 671px; height: 270px;"></strong></p>
<pre><strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated edges.</li>
</ul>

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Number of Connected Components in an Undirected Graph (Medium)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-complete-components
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int n) : id(n), size(n, 1) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        size[y] += size[x];
    }
    int getSize(int a) { return size[find(a)]; }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& E) {
        vector<int> degree(n);
        UnionFind uf(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            uf.connect(u, v);
            degree[u]++;
            degree[v]++;
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[uf.find(i)] += degree[i];
        }
        int ans = 0;
        for (auto &[r, c] : cnt) {
            int sz = uf.getSize(r);
            ans += sz * (sz - 1) == c;
        }
        return ans;
    }
};
```