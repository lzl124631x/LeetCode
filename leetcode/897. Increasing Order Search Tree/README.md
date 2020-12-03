# [897. Increasing Order Search Tree (Easy)](https://leetcode.com/problems/increasing-order-search-tree/)

<p>Given the <code>root</code> of a binary search tree, rearrange the tree in <strong>in-order</strong> so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg" style="width: 600px; height: 350px;">
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
<strong>Output:</strong> [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/17/ex2.jpg" style="width: 300px; height: 114px;">
<pre><strong>Input:</strong> root = [5,1,7]
<strong>Output:</strong> [1,null,5,null,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree will be in the range <code>[1, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1. In-order Traversal

```cpp
// OJ: https://leetcode.com/problems/increasing-order-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    TreeNode *prev;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        root->left = NULL;
        prev->right = root;
        prev = root; 
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode head;
        prev = &head;
        inorder(root);
        return head.right;
    }
};
```

## Solution 2. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/increasing-order-search-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    pair<TreeNode*, TreeNode*> dfs(TreeNode* root) {
        TreeNode *head = root, *tail = root;
        if (root->left) {
            auto [leftHead, leftTail] = dfs(root->left);
            head = leftHead;
            leftTail->right = root;
            root->left = NULL;
        }
        if (root->right) {
            auto [rightHead, rightTail] = dfs(root->right);
            root->right = rightHead;
            tail = rightTail;
        }
        return { head, tail };
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        return dfs(root).first;
    }
};
```