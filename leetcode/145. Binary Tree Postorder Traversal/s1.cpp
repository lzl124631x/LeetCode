// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<int> v;
    void rec(TreeNode* root) {
        if (!root) return;
        rec(root->left);
        rec(root->right);
        v.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        rec(root);
        return v;
    }
};