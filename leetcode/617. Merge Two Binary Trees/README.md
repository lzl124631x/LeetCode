# [617. Merge Two Binary Trees (Easy)](https://leetcode.com/problems/merge-two-binary-trees)

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

**Example 1:**  

```
Input: 
    Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
         3
        / \
       4   5
      / \   \ 
     5   4   7
```

**Note:** The merging process must start from the root nodes of both trees.

## Solution 1.

Simply follow the question description, you'll get the following recursive solution.

```cpp
// OJ: https://leetcode.com/problems/merge-two-binary-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 || !t2) return t1 ? t1 : t2;
    TreeNode *node = new TreeNode(t1->val + t2->val);
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);
    return node;
  }
};
```

For Oj, this solution is accepted. But for production, this solution generates a tree that has not only new nodes merged from old trees, but also pointers to the old trees. It means that if you destroy the old trees, the newly merged tree will be broken. To avoid this, use solution 2.

## Solution 2.

This solution is same as solution 1 except that for non-overlapping parts, it copy constructs the nodes.

```cpp
// OJ: https://leetcode.com/problems/merge-two-binary-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
  TreeNode *copy(TreeNode *root) {
    if (!root) return NULL;
    TreeNode *node = new TreeNode(root->val);
    node->left = copy(root->left);
    node->right = copy(root->right);
    return node;
  }
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 || !t2) return t1 ? copy(t1) : copy(t2);
    TreeNode *node = new TreeNode(t1->val + t2->val);
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);
    return node;
  }
};
```