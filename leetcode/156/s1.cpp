// OJ: https://leetcode.com/problems/binary-tree-upside-down/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        TreeNode *left = root->left, *right = root->right, *newRoot = NULL;
        while (left) {
            TreeNode *nextLeft = left->left, *nextRight = left->right;
            if (!newRoot) root->left = root->right = NULL;
            newRoot = left;
            newRoot->left = right;
            newRoot->right = root;
            root = left;
            left = nextLeft;
            right = nextRight;
        }
        return newRoot;
    }
};