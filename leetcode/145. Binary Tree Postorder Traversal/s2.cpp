// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *prev = NULL;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            if (!root->right || root->right == prev) {
                ans.push_back(root->val);
                s.pop();
                prev = root;
                root = NULL;
            } else root = root->right;
        }
        return ans;
    }
};