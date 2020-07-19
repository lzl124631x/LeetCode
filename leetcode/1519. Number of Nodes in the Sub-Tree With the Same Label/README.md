# [1519. Number of Nodes in the Sub-Tree With the Same Label (Medium)](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

<p>Given a tree (i.e. a connected, undirected graph that has no cycles) consisting of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code> and exactly <code>n - 1</code> <code>edges</code>. The <strong>root</strong> of the tree is the node <code>0</code>, and each node of the tree has <strong>a label</strong> which is a lower-case character given in the string <code>labels</code> (i.e. The node with the number <code>i</code> has the label <code>labels[i]</code>).</p>

<p>The <code>edges</code> array is given on the form <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>, which means there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Return <em>an array of size <code>n</code></em> where <code>ans[i]</code> is the number of nodes in the subtree of the&nbsp;<code>i<sup>th</sup></code>&nbsp;node which have the same label as node <code>i</code>.</p>

<p>A&nbsp;subtree&nbsp;of a tree&nbsp;<code>T</code> is the tree consisting of a node in <code>T</code> and all of its descendant&nbsp;nodes.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/01/q3e1.jpg" style="width: 441px; height: 321px;">
<pre><strong>Input:</strong> n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
<strong>Output:</strong> [2,1,1,1,1,1,1]
<strong>Explanation:</strong> Node 0 has label 'a' and its sub-tree has node 2 with label 'a' as well, thus the answer is 2. Notice that any node is part of its sub-tree.
Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 and 5, as nodes 4 and 5 have different labels than node 1, the answer is just 1 (the node itself).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/01/q3e2.jpg" style="width: 381px; height: 321px;">
<pre><strong>Input:</strong> n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
<strong>Output:</strong> [4,2,1,1]
<strong>Explanation:</strong> The sub-tree of node 2 contains only node 2, so the answer is 1.
The sub-tree of node 3 contains only node 3, so the answer is 1.
The sub-tree of node 1 contains nodes 1 and 2, both have label 'b', thus the answer is 2.
The sub-tree of node 0 contains nodes 0, 1, 2 and 3, all with label 'b', thus the answer is 4.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/07/01/q3e3.jpg" style="width: 381px; height: 321px;">
<pre><strong>Input:</strong> n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
<strong>Output:</strong> [3,2,1,1,1]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], labels = "cbabaa"
<strong>Output:</strong> [1,2,1,1,2,1]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]], labels = "aaabaaa"
<strong>Output:</strong> [6,5,4,1,3,2,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>,&nbsp;b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> !=&nbsp;b<sub>i</sub></code></li>
	<li><code>labels.length == n</code></li>
	<li><code>labels</code> is consisting of only of lower-case English letters.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<vector<int>> G;
    vector<int> ans, seen;
    vector<int> dfs(int u, string &labels) {
        seen[u] = 1;
        vector<int> cnt(26, 0);
        for (int v : G[u]) {
            if (seen[v]) continue;
            auto sub = dfs(v, labels);
            for (int i = 0; i < 26; ++i) cnt[i] += sub[i];
        }
        cnt[labels[u] - 'a']++;
        ans[u] = cnt[labels[u] - 'a'];
        return cnt;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& E, string labels) {
        G.assign(n, {});
        ans.assign(n, 0);
        seen.assign(n, 0);
        for (auto &e : E) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        dfs(0, labels);
        return ans;
    }
};
```