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