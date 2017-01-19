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
    vector<int> v;
    void rec(TreeNode* root) {
        if (!root) return;
        rec(root->left);
        v.push_back(root->val);
        rec(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        rec(root);
        return v;
    }
};