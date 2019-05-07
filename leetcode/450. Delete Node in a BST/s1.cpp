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