// OJ: https://leetcode.com/problems/find-bottom-left-tree-value
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  int maxDepth = 0, ans = 0;
  void dfs(TreeNode *root, int depth) {
    if (!root) return;
    if (depth > maxDepth) {
      ans = root->val;
      maxDepth = depth;
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
  }
public:
  int findBottomLeftValue(TreeNode* root) {
    dfs(root, 1);
    return ans;
  }
};