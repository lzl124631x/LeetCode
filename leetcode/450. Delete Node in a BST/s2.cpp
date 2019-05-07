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