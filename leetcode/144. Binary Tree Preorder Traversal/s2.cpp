// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while (s.size()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
};