// OJ: https://leetcode.com/problems/binary-tree-pruning/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return !root->left && !root->right && !root->val ? NULL : root;
    }
};