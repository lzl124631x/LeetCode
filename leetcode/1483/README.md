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
    vector<vector<int>> G, ids;
public:
    TreeAncestor(int n, vector<int>& parent) : nodeToId(n), idToNode(n), idToLevel(n), G(n) {
        for (int i = 1; i < n; ++i) G[parent[i]].push_back(i);
        int id = 0;
        function<void(int, int)> preorder = [&](int u, int level) {
            nodeToId[u] = id;
            idToNode[id] = u;
            idToLevel[id] = level;
            if (level == ids.size()) ids.emplace_back();
            ids[level].push_back(id);
            id++;
            for (int v : G[u]) preorder(v, level + 1);
        };
        preorder(0, 0);
    }
    int getKthAncestor(int node, int k) {
        int id = nodeToId[node], level = idToLevel[id];
        if (level - k < 0) return -1;
        auto &v = ids[level - k];
        return idToNode[*prev(lower_bound(begin(v), end(v), id))];
    }
};
```

## Solution 2. Binary Lifting

The brute force solution of this problem requires `O(K)` time for querying, which will result in TLE.

If we precompute all the `k`th ancester of `node`, the query will be `O(1)`, but the preparation will take `O(K^2)`.

One solution in between which doesn't require storing that much of data and also can boost the efficiency, is binary lifting.

The idea is that we break down the value based on binary representation.

So instead of storeing all `1, 2, 3, 4, 5, ...` values, we only store `1, 2, 4, 8, ...` values. We can use those `1, 2, 4, 8, ...` values to restore those values in between.

For example, a `6`th (`110` in base 2) parent is the same as the `4`th (`100` in base 2) parent of the `2`nd (`010` in base 2) parent.

Let `P[i][node]` be the `node`'s `2^i`th parent.

The `6`th parent of `node` can be expressed as `P[2][ P[1][node] ]`.

We can calculate `P` array using the following equation.
```
P[i][node] = P[i-1][ P[i-1][node] ]
```

What's the size of the first dimension of `P`? It means the maximum order of a parent + 1, i.e. the depth of the tree `h`. For example, a node in a tree of depth 3 can have at most 2nd parent, so the size of the first dimension of `P` is at least `3`.

We know that `n <= 5 * 10^4`. Given number of nodes in tree as `n`, what's the maximum height `h`? For a tree of height `h`, it at most have `2^h - 1` nodes. For a tree of height `h-1`, it at most have `2^(h-1) - 1` nodes. So, `2^(h-1) - 1 < n <= 2^h - 1`, `log(n+1) <= h < log(n+1) + 1`, `h = ceil(log(n+1))`. So, `h` is at most `ceil(log(5 * 10^4)) = ceil(15.6097) = 16`.

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
    int len; // len is at most `16` if `n <= 5e4`
public:
    TreeAncestor(int n, vector<int>& parent) {
        len = ceil(log(n + 1) / log(2));
        P.assign(len, vector<int>(parent.size(), -1));
        for (int node = 1; node < n; ++node) P[0][node] = parent[node]; // 2^0 = 1st parent
        for (int i = 1; i < len; ++i) { 
            for (int node = 0; node < n; ++node) {
                int p = P[i - 1][node];
                if (p != -1) P[i][node] = P[i - 1][p]; // 2^i-th parent is the 2^(i-1)-th  parent of the 2^(i-1)-th parent.
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < len && node != -1; ++i) {
            if ((k >> i & 1) == 0) continue; // If `k` has `0` at `i`th bit, skip.
            node = P[i][node];
        }
        return node;
    }
};
```
