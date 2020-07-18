# [1483. Kth Ancestor of a Tree Node (Hard)](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/)

<p>You are given a tree with&nbsp;<code>n</code>&nbsp;nodes numbered from&nbsp;<code>0</code>&nbsp;to&nbsp;<code>n-1</code>&nbsp;in the form of a parent array where <code>parent[i]</code>&nbsp;is the parent of node <code>i</code>. The root of the tree is node <code>0</code>.</p>

<p>Implement the function&nbsp;<code>getKthAncestor</code><code>(int node, int k)</code>&nbsp;to return the <code>k</code>-th ancestor of the given&nbsp;<code>node</code>. If there is no such ancestor, return&nbsp;<code>-1</code>.</p>

<p>The&nbsp;<em>k-th&nbsp;</em><em>ancestor</em>&nbsp;of a tree node is the <code>k</code>-th node&nbsp;in the path&nbsp;from that node to the root.</p>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/08/28/1528_ex1.png" style="width: 396px; height: 262px;"></strong></p>

<pre><b>Input:</b>
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

<b>Output:</b>
[null,1,0,-1]

<b>Explanation:</b>
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2);  // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3);  // returns -1 because there is no such ancestor
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;=&nbsp;n &lt;= 5*10^4</code></li>
	<li><code>parent[0] == -1</code>&nbsp;indicating that&nbsp;<code>0</code>&nbsp;is the root node.</li>
	<li><code>0 &lt;= parent[i] &lt; n</code>&nbsp;for all&nbsp;<code>0 &lt;&nbsp;i &lt; n</code></li>
	<li><code>0 &lt;= node &lt; n</code></li>
	<li>There will be at most <code>5*10^4</code> queries.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

Assign increasing ID to nodes via preorder traversal, then you will get the following relationship

```
      0                       0
    /   \                   /   \
   1     2       =>        1     4
  / \   / \               / \   / \
 3   4 5   6             2   3 5   6
```

We store the tree of the id's using `vector<vector<int>>`

```
[
    [0],
    [1,4],
    [2,3,5,6]
]
```

Then given a node, we can find the corresponding `id[node]`. For example `id[2] = 4`, `id[5] = 5`.

Also we can store the corresponding level of node. For example `level[5] = 2`.

Then if we want to find `getKthAncestor(5, 1)`, we can know that its parent is at level `level[5] - 1 = 1`.

Then in level `1`, we use binary search to find the largest id that is smaller than `id[5] = 5`. The parent id is `4`.

Then we use the id to find the corresponding node, `2`.

```cpp
// OJ: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
// Author: github.com/lzl124631x
// Time:
//      TreeAncestor: O(N)
//      getKthAncestor: O(logN)
// Space: O(N)
class TreeAncestor {
    vector<int> nodeToId, idToNode, idToLevel;
    vector<vector<int>> tree, G;
    void preorder(int node, int &id, int level) {
        if (level >= tree.size()) tree.emplace_back();
        tree[level].push_back(id);
        nodeToId[node] = id;
        idToNode[id] = node;
        idToLevel[id] = level;
        ++id;
        for (int child : G[node]) preorder(child, id, level + 1);
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        nodeToId.assign(n, 0);
        idToNode.assign(n, 0);
        idToLevel.assign(n, 0);
        G.assign(n, {});
        for (int i = 1; i < n; ++i) G[parent[i]].push_back(i);
        int id = 0;
        preorder(0, id, 0);
    }
    int getKthAncestor(int node, int k) {
        int id = nodeToId[node], level = idToLevel[id] - k;
        if (level < 0) return -1;
        return idToNode[*(upper_bound(begin(tree[level]), end(tree[level]), id) - 1)];
    }
};
```

## Solution 2. Binary Lifting

```cpp
// OJ: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
// Author: github.com/lzl124631x
// Time:
//      TreeAncestor: O(log(max(K)) * N)
//      getKthAncestor: O(logK)
// Space: O(N)
// Ref: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686268/Explanation-for-this-question-c%2B%2B-sample-code
class TreeAncestor {
    vector<vector<int>> P;
public:
    TreeAncestor(int n, vector<int>& parent) {
        P.assign(20, vector<int>(parent.size(), -1));
        for (int i = 0; i < parent.size(); ++i) P[0][i] = parent[i];
        for (int i = 1; i < 20; ++i) {
            for (int node = 0; node < parent.size(); ++node) {
                int p = P[i - 1][node];
                if (p != -1) P[i][node] = P[i - 1][p];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; ++i) {
            if ((k & (1 << i)) == 0) continue;
            node = P[i][node];
            if (node == -1) return -1;
        }
        return node;
    }
};
```
