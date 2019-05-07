# [450. Delete Node in a BST (Medium)](https://leetcode.com/problems/delete-node-in-a-bst/)

<p>Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.</p>

<p>Basically, the deletion can be divided into two stages:
</p><ol>
<li>Search for a node to remove.</li>
<li>If the node is found, delete the node.</li>
</ol>
<p></p>

<p><b>Note:</b> Time complexity should be O(height of tree).</p>

<p><b>Example:</b>
</p><pre>root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
</pre>
<p></p>

**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->left) {
            auto node = root->left;
            while (node->right) node = node->right;
            root->val = node->val;
            root->left = deleteNode(root->left, root->val);
        } else if (root->right) {
            auto node = root->right;
            while (node->left) node = node->left;
            root->val = node->val;
            root->right = deleteNode(root->right, root->val);
        } else {
            delete root;
            root = NULL;
        }
        return root;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (!root->left) {
            auto right = root->right;
            delete root;
            return right;
        } else if (!root->right) {
            auto left = root->left;
            delete root;
            return left;
        } else {
            auto node = root->right;
            while (node->left) node = node->left;
            root->val = node->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};
```