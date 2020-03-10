// OJ: https://leetcode.com/problems/longest-univalue-path/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if (root->left && root->left->val == root->val) ++left;
        else left = 0;
        if (root->right && root->right->val == root->val) ++right;
        else right = 0;
        ans = max(ans, left + right);
        return max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};