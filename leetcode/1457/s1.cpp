// OJ: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int cnt[10] = {}, odd = 0, ans = 0;
    void dfs(TreeNode *root) {
        if (!root) return;
        cnt[root->val]++;
        int diff = cnt[root->val] % 2 ? 1 : -1;
        odd += diff;
        ans += !root->left && !root->right && odd < 2;
        dfs(root->left);
        dfs(root->right);
        odd -= diff;
        cnt[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};