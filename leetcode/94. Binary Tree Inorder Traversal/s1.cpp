// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};