// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<int> v;
    void rec(TreeNode *root) {
        if (!root) return;
        v.push_back(root->val);
        rec(root->left);
        rec(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        rec(root);
        return v;
    }
};