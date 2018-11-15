// OJ: https://leetcode.com/problems/increasing-order-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(log(N))
class Solution {
private:
    TreeNode *node;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        root->left = NULL;
        node->right = root;
        node = node->right;
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode head(0);
        node = &head;
        inorder(root);
        return head.right;
    }
};