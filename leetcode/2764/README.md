# [2764. is Array a Preorder of Some ‌Binary Tree (Medium)](https://leetcode.com/problems/is-array-a-preorder-of-some-binary-tree)

<p>Given a <strong>0-indexed</strong> integer <strong>2D array</strong> <code>nodes</code>, your task is to determine if the given array represents the <strong>preorder</strong> traversal of some <strong>binary</strong> tree.</p>
<p>For each index <code>i</code>, <code>nodes[i] = [id, parentId]</code>, where <code>id</code> is the id of the node at the index <code>i</code> and <code>parentId</code> is the id of its parent in the tree (if the node has no parent, then <code>parentId = -1</code>).</p>
<p>Return <code>true</code> <em>if the given array&nbsp;</em><em>represents the preorder traversal of some tree, and</em> <code>false</code> <em>otherwise.</em></p>
<p><strong>Note:</strong> the <strong>preorder</strong> traversal of a tree is a recursive way to traverse a tree in which we first visit the current node, then we do the preorder traversal for the left child, and finally, we do it for the right child.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nodes = [[0,-1],[1,0],[2,0],[3,2],[4,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong> The given nodes make the tree in the picture below.
We can show that this is the preorder traversal of the tree, first we visit node 0, then we do the preorder traversal of the right child which is [1], then we do the preorder traversal of the left child which is [2,3,4].
</pre>
<p><img alt="" src="https://assets.leetcode.com/uploads/2023/07/04/1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 250px; height: 251px;"></p>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nodes = [[0,-1],[1,0],[2,0],[3,1],[4,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> The given nodes make the tree in the picture below.
For the preorder traversal, first we visit node 0, then we do the preorder traversal of the right child which is [1,3,4], but we can see that in the given order, 2 comes between 1 and 3, so, it's not the preorder traversal of the tree.
</pre>
<p><img alt="" src="https://assets.leetcode.com/uploads/2023/07/04/2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 250px; height: 251px;"></p>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nodes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nodes[i].length == 2</code></li>
	<li><code>0 &lt;= nodes[i][0] &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= nodes[i][1] &lt;= 10<sup>5</sup></code></li>
	<li>The input is generated such that <code>nodes</code> make a binary tree.</li>
</ul>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/is-array-a-preorder-of-some-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPreorder(vector<vector<int>>& A) {
        int N = A.size(), i = 0, root = -1;
        unordered_map<int, vector<int>> G;
        for (auto &n : A) {
            if (n[1] == -1) root = n[0];
            else G[n[1]].push_back(n[0]);
        }
        function<bool(int)> dfs = [&](int u) {
            if (A[i++][0] != u) return false;
            for (int v : G[u]) {
                if (!dfs(v)) return false;
            }
            return true;
        };
        return dfs(root);
    }
};
```