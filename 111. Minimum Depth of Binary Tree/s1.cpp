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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int d = INT_MAX;
        if (root->left) d = min(d, minDepth(root->left));
        if (root->right) d = min(d, minDepth(root->right));
        return 1 + d;
    }
};