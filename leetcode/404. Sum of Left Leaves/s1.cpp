// OJ: https://leetcode.com/problems/sum-of-left-leaves
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  int dfs(TreeNode *root, bool isLeftChild) {
    if (!root) return 0;
    if (!root->left && !root->right && isLeftChild) return root->val;
    return dfs(root->left, true) + dfs(root->right, false);
  }
public:
  int sumOfLeftLeaves(TreeNode* root) {
    return dfs(root, false);
  }
};