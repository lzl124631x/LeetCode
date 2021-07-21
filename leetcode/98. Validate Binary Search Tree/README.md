# [98. Validate Binary Search Tree (Medium)](https://leetcode.com/problems/validate-binary-search-tree/)

<p>Given the <code>root</code> of a binary tree, <em>determine if it is a valid binary search tree (BST)</em>.</p>

<p>A <strong>valid BST</strong> is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than</strong> the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg" style="width: 302px; height: 182px;">
<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg" style="width: 422px; height: 292px;">
<pre><strong>Input:</strong> root = [5,1,4,null,null,3,6]
<strong>Output:</strong> false
<strong>Explanation:</strong> The root node's value is 5 but its right child's value is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Zillow](https://leetcode.com/company/zillow), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Find Mode in Binary Search Tree (Easy)](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

## Solution 1. Pre-order Traversal

```cpp
// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode *left = NULL, TreeNode *right = NULL) {
        if (!root) return true;
        if ((left && root->val <= left->val) || (right && root->val >= right->val)) return false;
        return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/validate-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isValidBST(TreeNode* root, long left = LONG_MIN, long right = LONG_MAX) {
        if (!root) return true;
        if (root->val <= left || root->val >= right) return false;
        return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
    }
};
```

## Solution 2. In-order traversal

```cpp
// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
    TreeNode *prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left) || (prev && prev->val >= root->val)) return false; 
        prev = root;
        return isValidBST(root->right);
    }
};
```