# [924. Minimize Malware Spread (Hard)](https://leetcode.com/problems/minimize-malware-spread)

<p>You are given a network of <code>n</code> nodes represented as an <code>n x n</code> adjacency matrix <code>graph</code>, where the <code>i<sup>th</sup></code> node is directly connected to the <code>j<sup>th</sup></code> node if <code>graph[i][j] == 1</code>.</p>

<p>Some nodes <code>initial</code> are initially infected by malware. Whenever two nodes are directly connected, and at least one of those two nodes is infected by malware, both nodes will be infected by malware. This spread of malware will continue until no more nodes can be infected in this manner.</p>

<p>Suppose <code>M(initial)</code> is the final number of nodes infected with malware in the entire network after the spread of malware stops. We will remove <strong>exactly one node</strong> from <code>initial</code>.</p>

<p>Return the node that, if removed, would minimize <code>M(initial)</code>. If multiple nodes could be removed to minimize <code>M(initial)</code>, return such a node with <strong>the smallest index</strong>.</p>

<p>Note that if a node was removed from the <code>initial</code> list of infected nodes, it might still be infected later due to the malware spread.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
<strong>Output:</strong> 0
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
<strong>Output:</strong> 0
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
<strong>Output:</strong> 1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>n == graph[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 300</code></li>
	<li><code>graph[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>graph[i][j] == graph[j][i]</code></li>
	<li><code>graph[i][i] == 1</code></li>
	<li><code>1 &lt;= initial.length &lt;= n</code></li>
	<li><code>0 &lt;= initial[i] &lt;= n - 1</code></li>
	<li>All the integers in <code>initial</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google), [Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Matrix](https://leetcode.com/tag/matrix/)

## Solution 1. Union Find

Use UnionFind to count the infected nodes given `initial` array and a skipped initial node. Find the skipped initial node that results in minimum infected count.

```cpp
// OJ: https://leetcode.com/problems/minimize-malware-spread/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int n) : id(n), size(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        size[y] += size[x];
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    int getSize(int a) {
        return size[find(a)];
    }
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int N = graph.size(), ans = initial[0], minInfected = INT_MAX;
        sort(initial.begin(), initial.end());
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (graph[i][j]) uf.connect(i, j);
            }
        }
        for (int i = 0; i < initial.size(); ++i) {
            int cnt = 0; // M(initial) if we skip initial[i]
            unordered_set<int> s;
            for (int j = 0; j < initial.size(); ++j) {
                if (j == i) continue;
                int r = uf.find(initial[j]);
                if (s.count(r)) continue;
                s.insert(r);
                cnt += uf.getSize(r);
            }
            if (cnt < minInfected) {
                ans = initial[i];
                minInfected = cnt;
            }
        }
        return ans;
    }
};
```

## Solution 2. Union Find

Find the initial node that belongs to the largest connected component with only one initial node in it.

If there is no such a node, return the smallest index of initial nodes.

```cpp
// OJ: https://leetcode.com/problems/minimize-malware-spread/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
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
        id[y] = x; // make sure find(a), i.e. x, is always used as the root
        size[x] += size[y];
    }
    int getSize(int a) { return size[find(a)]; }
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& G, vector<int>& A) {
        sort(begin(A), end(A));
        int N = G.size(), ans = A[0], maxSize = 0;
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (G[i][j]) uf.connect(i, j); // make sure the smaller index is always used as root
            }
        }
        // Find the largest graph component with a single initial node
        unordered_map<int, int> m; // graph component root -> number of initial nodes in this graph component
        for (int i : A) m[uf.find(i)]++;
        for (int i : A) {
            int s = uf.getSize(i);
            if (m[uf.find(i)] == 1 && s > maxSize) {
                ans = i;
                maxSize = s;
            }
        }
        return ans;
    }
};
```

## Solution 3. Component Coloring (DFS)

```cpp
// OJ: https://leetcode.com/problems/minimize-malware-spread/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    void dfs(vector<vector<int>> &graph, int start, int c, vector<int> &color) {
        color[start] = c;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[start][i] && !color[i]) dfs(graph, i, c, color);
        }
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        unordered_set<int> init(initial.begin(), initial.end());
        sort(initial.begin(), initial.end());
        int N = graph.size(), c = 0, ans = initial[0], maxSize = 0;
        vector<int> color(N);
        for (int n : initial) {
            if (color[n]) continue;
            dfs(graph, n, ++c, color);
        }
        for (int i = 1; i <= c; ++i) {
            int cnt = 0, mal = INT_MAX, malCnt = 0;
            for (int j = 0; j < N; ++j) {
                if (color[j] == i) {
                    cnt++;
                    if (init.count(j)) {
                        mal = min(mal, j);
                        ++malCnt;
                    }
                }
            }
            if (malCnt == 1 && cnt > maxSize) {
                maxSize = cnt;
                ans = mal;
            }
        }
        return ans;
    }
};
```