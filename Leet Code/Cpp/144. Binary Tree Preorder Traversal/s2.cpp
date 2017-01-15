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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
};