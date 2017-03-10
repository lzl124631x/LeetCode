// OJ: https://leetcode.com/problems/find-bottom-left-tree-value
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  int ans, maxHeight = 0;
  void preorder(TreeNode* root, int height) {
    if (!root) return;
    if (height > maxHeight) {
      maxHeight = height;
      ans = root->val;
    }
    preorder(root->left, height + 1);
    preorder(root->right, height + 1);
  }
public:
  int findBottomLeftValue(TreeNode* root) {
    preorder(root, 1);
    return ans;
  }
};