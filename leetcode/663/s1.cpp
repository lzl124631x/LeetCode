// OJ: https://leetcode.com/problems/equal-tree-partition/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(logN)
class Solution {
public:
    int getSum(TreeNode *root) {
        if (!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    bool dfs(TreeNode *root, int target) {
        if (!root) return false;
        int sum = getSum(root);
        if (sum == target) return true;
        if (sum - root->val < target) return false;
        return dfs(root->left, target) || dfs(root->right, target);
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int sum = getSum(root);
        if (sum % 2) return false;
        return dfs(root->left, sum / 2) || dfs(root->right, sum / 2);
    }
};