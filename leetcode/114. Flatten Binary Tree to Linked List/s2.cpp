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
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *prev = NULL;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (prev) {
                prev->left = NULL;
                prev->right = root;
            }
            prev = root;
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
    }
};