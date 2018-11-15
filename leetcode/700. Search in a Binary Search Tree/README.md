# [700. Search in a Binary Search Tree (Easy)](https://leetcode.com/problems/search-in-a-binary-search-tree)

Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example, 

Given the tree:

        4
       / \
      2   7
     / \
    1   3

And the value to search: 2

You should return this subtree:

      2     
     / \ 
    1   3

In the example above, if we want to search the value `5`, since there is no node with value `5`, we should return `NULL`.

Note that an empty tree is represented by `NULL`, therefore you would see the expected output (serialized tree format) as `[]`, not `null`.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(log(N))
// Space: O(log(N))
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        return val > root->val ? searchBST(root->right, val) : searchBST(root->left, val);
    }
};
```