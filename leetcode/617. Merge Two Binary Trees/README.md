# [617. Merge Two Binary Trees (Easy)](https://leetcode.com/problems/merge-two-binary-trees/)

<p>You are given two binary trees <code>root1</code> and <code>root2</code>.</p>

<p>Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.</p>

<p>Return <em>the merged tree</em>.</p>

<p><strong>Note:</strong> The merging process must start from the root nodes of both trees.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/merge.jpg" style="width: 600px; height: 163px;">
<pre><strong>Input:</strong> root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
<strong>Output:</strong> [3,4,5,5,4,null,7]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root1 = [1], root2 = [1,2]
<strong>Output:</strong> [2,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in both trees is in the range <code>[0, 2000]</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

Simply follow the question description, you'll get the following recursive solution.

```cpp
// OJ: https://leetcode.com/problems/merge-two-binary-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a ? a : b;
        auto node = new TreeNode(a->val + b->val);
        node->left = mergeTrees(a->left, b->left);
        node->right = mergeTrees(a->right, b->right);
        return node;
    }
};
```

This solution is accepted by the OJ. But in real world, this solution generates a tree that has not only new nodes merged from old trees, but also pointers to the old trees. It means that if you destroy the old trees, the newly merged tree will be broken. To avoid this, use solution 2.

## Solution 2.

This solution is same as solution 1 except that for non-overlapping parts, it copy constructs the nodes.

```cpp
// OJ: https://leetcode.com/problems/merge-two-binary-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode *copy(TreeNode *root) {
        if (!root) return NULL;
        auto node = new TreeNode(root->val);
        node->left = copy(root->left);
        node->right = copy(root->right);
        return node;
    }
public:
    TreeNode* mergeTrees(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a ? copy(a) : copy(b);
        auto node = new TreeNode(a->val + b->val);
        node->left = mergeTrees(a->left, b->left);
        node->right = mergeTrees(a->right, b->right);
        return node;
    }
};
```