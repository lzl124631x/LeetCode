# [2316. Count Unreachable Pairs of Nodes in an Undirected Graph (Medium)](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph)

<p>You are given an integer <code>n</code>. There is an <strong>undirected</strong> graph with <code>n</code> nodes, numbered from <code>0</code> to <code>n - 1</code>. You are given a 2D integer array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> denotes that there exists an <strong>undirected</strong> edge connecting nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>
<p>Return <em>the <strong>number of pairs</strong> of different nodes that are <strong>unreachable</strong> from each other</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/05/tc-3.png" style="width: 267px; height: 169px;">
<pre><strong>Input:</strong> n = 3, edges = [[0,1],[0,2],[1,2]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/05/tc-2.png" style="width: 295px; height: 269px;">
<pre><strong>Input:</strong> n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
<strong>Output:</strong> 14
<strong>Explanation:</strong> There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated edges.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
// Author: github.com/lzl124631x
// Time: O(NlogN * K^2) where K is the number of unique graph component sizes
// Space: O(N)
class UnionFind {
    vector<int> id, size;
public:
    UnionFind(int N) : id(N), size(N, 1) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[q] = p;
        size[p] += size[q];
    }
    int getSize(int a) {
        return size[find(a)];
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& E) {
        UnionFind uf(n);
        for (auto &e : E) uf.connect(e[0], e[1]);
        unordered_set<int> seen;
        long long ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int r = uf.find(i);
            if (seen.count(r)) continue;
            seen.insert(r);
            cnt[uf.getSize(r)]++;
        }
        for (auto a = cnt.begin(); a != cnt.end(); ++a) {
            long long sa = a->first, ca = a->second;
            ans += sa * sa * ca * (ca - 1) / 2;
            for (auto b = next(a); b != cnt.end(); ++b) {
                long long sb = b->first, cb = b->second;
                ans += sa * sb * ca * cb;
            }
        }
        return ans;
    }
};
```