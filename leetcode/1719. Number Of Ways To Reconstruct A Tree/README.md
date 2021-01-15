# [1719. Number Of Ways To Reconstruct A Tree (Hard)](https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/)

<p>You are given an array <code>pairs</code>, where <code>pairs[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>, and:</p>

<ul>
	<li>There are no duplicates.</li>
	<li><code>x<sub>i</sub> &lt; y<sub>i</sub></code></li>
</ul>

<p>Let <code>ways</code> be the number of rooted trees that satisfy the following conditions:</p>

<ul>
	<li>The tree consists of nodes whose values appeared in <code>pairs</code>.</li>
	<li>A pair <code>[x<sub>i</sub>, y<sub>i</sub>]</code> exists in <code>pairs</code> <strong>if and only if</strong> <code>x<sub>i</sub></code> is an ancestor of <code>y<sub>i</sub></code> or <code>y<sub>i</sub></code> is an ancestor of <code>x<sub>i</sub></code>.</li>
	<li><strong>Note:</strong> the tree does not have to be a binary tree.</li>
</ul>

<p>Two ways are considered to be different if there is at least one node that has different parents in both ways.</p>

<p>Return:</p>

<ul>
	<li><code>0</code> if <code>ways == 0</code></li>
	<li><code>1</code> if <code>ways == 1</code></li>
	<li><code>2</code> if <code>ways &gt; 1</code></li>
</ul>

<p>A <strong>rooted tree</strong> is a tree that has a single root node, and all edges are oriented to be outgoing from the root.</p>

<p>An <strong>ancestor</strong> of a node is any node on the path from the root to that node (excluding the node itself). The root has no ancestors.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2020/12/03/trees2.png" style="width: 208px; height: 221px;">
<pre><strong>Input:</strong> pairs = [[1,2],[2,3]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is exactly one valid rooted tree, which is shown in the above figure.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/03/tree.png" style="width: 234px; height: 241px;">
<pre><strong>Input:</strong> pairs = [[1,2],[2,3],[1,3]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are multiple valid rooted trees. Three of them are shown in the above figures.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> pairs = [[1,2],[2,3],[2,4],[1,5]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no valid rooted trees.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pairs.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x<sub>i </sub>&lt; y<sub>i</sub> &lt;= 500</code></li>
	<li>The elements in <code>pairs</code> are unique.</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1.

The thing to note is that if something is the root of a subtree, then it must be paired with all of its descendants (and its ancestors). So a parent's pairings will always contain a child's pairings.

So, if we use the pairs to create an adjacency list, we can proceed **greedily** by always selecting the node with greatest degree (here, we're talking about the degree in the graph formed by pairs, not the tree), and finding its parent. Since we proceed top-down, the already visited adjacencies are the node's ancestors, and its parent is the one with least degree. We then have to check the condition that the parent's adjacencies contain the child's adjacencies (aside from itself).

So:

1.  Construct adjacency list from pairs
2.  Repeatedly take node with greatest degree
3.  Choose parent to be adjacency with least degree among those that have been visited  
    a. If the node is the first, i.e. parent is none, check if node is the root, else return 0.
4.  Parent's adjacencies must contain the node's adjacencies, except the parent itself, else return 0.
5.  If parent and it have the same degree, you could visit them in either order, so there might be multiple answers.
6.  If you iterated through every node, return 2 or 1 depending on step 6.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/
// Author: github.com/lzl124631x
// Ref: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/discuss/1008950/Simple-C%2B%2B-solution
class Solution {
public:
    int checkWays(vector<vector<int>>& A) {
        unordered_map<int, unordered_set<int>> G;
        for (auto &p : A) { // build gragh using the pairs
            int u = p[0], v = p[1];
            G[u].insert(v);
            G[v].insert(u);
        }
        priority_queue<pair<int, int>> pq;
        for (auto &[u, vs] : G) pq.emplace(vs.size(), u);
        int N = pq.size();
        bool multiple = false;
        unordered_set<int> seen;
        while (pq.size()) {
            auto [sz, u] = pq.top(); // greedily pick the node with the greatest degree.
            pq.pop();
            int parent = 0, parentDegree = N + 1;
            if (seen.size()) {
                for (int v : G[u]) {
                    if (G[v].size() < parentDegree && seen.count(v)) {
                        parent = v; // the parent is a visited neighbor of `u` with the smallest degree.
                        parentDegree = G[v].size();
                    }
                }
            }
            seen.insert(u);
            if (parent == 0) {
                if (sz != N - 1) return 0; // the first root's degree must be N - 1
                continue;
            }
            for (int v : G[u]) {
                if (v == parent) continue;
                if (G[parent].count(v) == 0) return 0; // the parent must connect to all the neighbors of `u` except itself.
            }
            if (parentDegree == sz) multiple = true; // if the parent degree and the current node's degree are the same, we can visit them in any order, so there might be multiple answers.
        }
        return multiple ? 2 : 1;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/
// Author: github.com/lzl124631x
class Solution {
public:
    int checkWays(vector<vector<int>>& A) {
        unordered_map<int, unordered_set<int>> G;
        for (auto &p : A) {
            int u = p[0], v = p[1];
            G[u].insert(v);
            G[v].insert(u);
        }
        function<int(vector<int>&)> solve = [&](vector<int> &nodes) {
            vector<pair<int, int>> pairs; // degree, node
            for (int n : nodes) pairs.emplace_back(G[n].size(), n);
            sort(begin(pairs), end(pairs), greater<>());
            int rootDegree = nodes.size() - 1;
            if (pairs[0].first != rootDegree) return 0; // can't find root
            unordered_map<int, vector<int>> comp;
            unordered_set<int> seen;
            int id = 0, rootCnt = 0;
            function<void(int)> dfs = [&](int u) {
                seen.insert(u);
                comp[id].push_back(u);
                for (int v : G[u]) {
                    if (seen.count(v) == 0) dfs(v);
                }
            };
            for (auto &[deg, u] : pairs) {
                if (deg == rootDegree) {
                    ++rootCnt;
                    for (int v : G[u]) G[v].erase(u);
                } else if (seen.count(u) == 0) {
                    dfs(u); // non-root nodes are split into different components. Each component is a subtree and solved independently.
                    ++id;
                }
            }
            int ans = 1;
            for (auto &[i, ns] : comp) {
                int cnt = solve(ns);
                if (cnt == 0) return 0;
                if (cnt == 2) ans = 2;
            }
            return rootCnt > 1 ? 2 : ans;
        };
        vector<int> nodes;
        for (auto &[u, _] : G) nodes.push_back(u);
        return solve(nodes);
    }
};
```