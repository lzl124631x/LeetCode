/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *helper(TreeNode *root) {
        TreeNode *right = root->right, *end = root;
        if (root->left) {
            end = helper(root->left);
            end->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if (right) {
            end = helper(right);
        }
        return end;
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        helper(root);
    }
};