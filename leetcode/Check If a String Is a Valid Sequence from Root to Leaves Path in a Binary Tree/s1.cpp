// OJ: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/532/week-5/3315/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    bool dfs(TreeNode* root, vector<int> &A, int i) {
        if (i >= A.size()) return false;
        if (!root || root->val != A[i]) return false;
        if (i == A.size() - 1) return !root->left && !root->right;
        return dfs(root->left, A, i + 1) || dfs(root->right, A, i + 1);
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (!root) return arr.size() == 0;
        return dfs(root, arr, 0);
    }
};