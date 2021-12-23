# [1123. Lowest Common Ancestor of Deepest Leaves (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)

<p>Given the <code>root</code> of a binary tree, return <em>the lowest common ancestor of its deepest leaves</em>.</p>

<p>Recall that:</p>

<ul>
	<li>The node of a binary tree is a leaf if and only if it has no children</li>
	<li>The depth of the root of the tree is <code>0</code>. if the depth of a node is <code>d</code>, the depth of each of its children is <code>d + 1</code>.</li>
	<li>The lowest common ancestor of a set <code>S</code> of nodes, is the node <code>A</code> with the largest depth such that every node in <code>S</code> is in the subtree with root <code>A</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png" style="width: 600px; height: 510px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4]
<strong>Output:</strong> [2,7,4]
<strong>Explanation:</strong> We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The root is the deepest node in the tree, and it's the lca of itself.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [0,1,3,null,2]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> The deepest leaf node in the tree is 2, the lca of one node is itself.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[1, 1000]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li>The values of the nodes in the tree are <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Note:</strong> This question is the same as 865: <a href="https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/" target="_blank">https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/</a></p>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Lowest Common Ancestor of a Binary Tree IV (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int maxDepth = -1, target = 0, cnt = 0;
    void count(TreeNode *root, int d) {
        if (!root) return;
        if (d > maxDepth) {
            target = 1;
            maxDepth = d;
        } else if (d == maxDepth) ++target;
        count(root->left, d + 1);
        count(root->right, d + 1);
    }
    TreeNode *find(TreeNode *root, int d) {
        if (!root) return NULL;
        int before = cnt;
        auto left = find(root->left, d + 1);
        if (left) return left;
        auto right = find(root->right, d + 1);
        if (right) return right;
        if (d == maxDepth) ++cnt;
        return before == 0 && cnt == target ? root : NULL;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        count(root, 0);
        return find(root, 0);
    }
};
```

## Solution 2.

The lowest ancester is the highest node whose left and right subtrees have the same height.

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    pair<TreeNode*, int> dfs(TreeNode *root, int d = 0) { // latest node which has equal depth in left and right sub-trees; the corresponding height
        if (!root) return {nullptr, d};
        const auto &[left, ld] = dfs(root->left, d + 1);
        const auto &[right, rd] = dfs(root->right, d + 1);
        if (ld > rd) return {left, ld};
        if (ld < rd) return {right, rd};
        return {root, ld};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
```