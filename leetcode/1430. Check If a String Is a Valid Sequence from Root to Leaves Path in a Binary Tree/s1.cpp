// OJ: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/
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