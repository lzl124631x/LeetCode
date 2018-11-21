# [701. Insert into a Binary Search Tree (Medium)](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

<p>Given the root node of a binary search tree (BST) and a value to be inserted into the tree,&nbsp;insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.</p>

<p>Note that there may exist&nbsp;multiple valid ways for the&nbsp;insertion, as long as the tree remains a BST after insertion. You can return any of them.</p>

<p>For example,&nbsp;</p>

<pre>Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
</pre>

<p>You can return this binary search tree:</p>

<pre>         4
       /   \
      2     7
     / \   /
    1   3 5
</pre>

<p>This tree is also valid:</p>

<pre>         5
       /   \
      2     7
     / \   
    1   3
         \
          4
</pre>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val > root->val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        return root;
    }
};
```