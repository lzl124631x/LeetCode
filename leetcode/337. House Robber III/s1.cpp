// OJ: https://leetcode.com/problems/house-robber-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        auto a = dfs(root->left), b = dfs(root->right);
        return { root->val + a.second + b.second, max(a.first, a.second) + max(b.first, b.second) };
    }
public:
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};