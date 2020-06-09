// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<int> ans;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};