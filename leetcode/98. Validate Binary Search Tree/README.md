# [98. Validate Binary Search Tree (Medium)](https://leetcode.com/problems/validate-binary-search-tree/)

<p>Given a binary tree, determine if it is a valid binary search tree (BST).</p>

<p>Assume a BST is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than</strong> the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre>    2
   / \
  1   3

<strong>Input:</strong>&nbsp;[2,1,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre>    5
   / \
  1   4
&nbsp;    / \
&nbsp;   3   6

<strong>Input:</strong> [5,1,4,null,null,3,6]
<strong>Output:</strong> false
<strong>Explanation:</strong> The root node's value is 5 but its right child's value is 4.
</pre>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Find Mode in Binary Search Tree (Easy)](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  bool isValidBST(TreeNode *root, TreeNode *lb, TreeNode *rb) {
    if (!root) return true;
    if ((lb && root->val <= lb->val) || (rb && root->val >= rb->val)) return false;
    return isValidBST(root->left, lb, root) && isValidBST(root->right, root, rb);
  }
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
  }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  TreeNode *last = NULL;
public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    if (!isValidBST(root->left) || (last && last->val >= root->val)) return false;
    last = root;
    return isValidBST(root->right);
  }
};
```