// OJ: https://leetcode.com/problems/inorder-successor-in-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    TreeNode *target, *ans = NULL;
    bool seen = false;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (seen && !ans) ans = root;
        if (seen && ans) return;
        if (root == target) seen = true;
        inorder(root->right);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        target = p;
        inorder(root);
        return ans;
    }
};