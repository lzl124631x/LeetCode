# [928. Minimize Malware Spread II (Hard)](https://leetcode.com/problems/minimize-malware-spread-ii/)

<p>(This problem is the same as <em>Minimize Malware Spread</em>, with the differences bolded.)</p>

<p>In a network of nodes, each node <code>i</code> is directly connected to another node <code>j</code> if and only if&nbsp;<code>graph[i][j] = 1</code>.</p>

<p>Some nodes <code>initial</code> are initially infected by malware.&nbsp; Whenever two nodes are directly connected and at least one of those two nodes is infected by malware, both nodes will be infected by malware.&nbsp; This spread of malware will continue until no more nodes can be infected in this manner.</p>

<p>Suppose <code>M(initial)</code>&nbsp;is the final number of nodes infected with malware in the entire network, after the spread of malware stops.</p>

<p>We will&nbsp;remove one node from the initial list, <strong>completely removing it and any connections from this node to any other node</strong>.&nbsp; Return the node that if removed, would minimize&nbsp;<code>M(initial)</code>.&nbsp; If multiple nodes could be removed to minimize <code>M(initial)</code>, return such a node with the smallest index.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>graph = <span id="example-input-1-1">[[1,1,0],[1,1,0],[0,0,1]]</span>, initial = <span id="example-input-1-2">[0,1]</span>
<strong>Output: </strong><span id="example-output-1">0</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>graph = <span id="example-input-2-1">[[1,1,0],[1,1,1],[0,1,1]]</span>, initial = <span id="example-input-2-2">[0,1]</span>
<strong>Output: </strong><span id="example-output-2">1</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>graph = <span id="example-input-3-1">[[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]]</span>, initial = <span id="example-input-3-2">[0,1]</span>
<strong>Output: </strong><span id="example-output-3">1</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt; graph.length = graph[0].length &lt;= 300</code></li>
	<li><code>0 &lt;= graph[i][j] == graph[j][i] &lt;= 1</code></li>
	<li><code>graph[i][i] = 1</code></li>
	<li><code>1 &lt;= initial.length &lt; graph.length</code></li>
	<li><code>0 &lt;= initial[i] &lt; graph.length</code></li>
</ol>
</div>
</div>
</div>

**Companies**:  
[Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/minimize-malware-spread-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class UnionFind {
private:
    vector<int> rank, id, size;
public:
    UnionFind(int n): rank(n), id(n), size(n, 1) {
        for (int i = 0; i < n; ++i) id[i] = i;
    }
    int find(int p) {
        if (id[p] == p) return p;
        return id[p] = find(id[p]);
    }
    void connect(int p, int q) {
        int a = find(p), b = find(q);
        if (a == b) return;
        if (rank[a] > rank[b]) {
            id[b] = a;
            size[a] += size[b];
        } else {
            if (rank[a] == rank[b]) ++rank[b];
            id[a] = b;
            size[b] += size[a];
        }
    }
    int getUnionSize(int p) {
        return size[find(p)];
    }
};
class Solution {
private:
    int getInfectedCount(vector<vector<int>>& graph, int skip, vector<int>& initial) {
        int N = graph.size(), ans = 0;
        UnionFind uf(N);
        for (int i = 0; i < N; ++i) {
            if (i == skip) continue;
            for (int j = i + 1; j < N; ++j) {
                if (j == skip || !graph[i][j]) continue;
                uf.connect(i, j);
            }
        }
        unordered_set<int> s;
        for (int n : initial) s.insert(uf.find(n));
        for (int n : s) ans += uf.getUnionSize(n);
        return ans;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int ans = initial[0], minCnt = INT_MAX;
        sort(initial.begin(), initial.end());
        for (int n : initial) {
            int cnt = getInfectedCount(graph, n, initial);
            if (cnt < minCnt) {
                ans = n;
                minCnt = cnt;
            }
        }
        return ans;
    }
};
```