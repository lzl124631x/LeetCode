// OJ: https://leetcode.com/problems/house-robber-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = dfs(root->left), right = dfs(root->right);
        int prev = left.first + right.first;
        return { max(root->val + left.second + right.second, prev), prev };
    }
public:
    int rob(TreeNode* root) {
        return dfs(root).first;
    }
};