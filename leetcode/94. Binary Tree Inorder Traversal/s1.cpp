// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
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