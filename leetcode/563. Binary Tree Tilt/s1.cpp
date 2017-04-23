// OJ: https://leetcode.com/problems/binary-tree-tilt
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  int tilt = 0;
  int traverse(TreeNode *root) {
    if (!root) return 0;
    int left = traverse(root->left), right = traverse(root->right);
    tilt += abs(left - right);
    return left + right + root->val;
  }
public:
  int findTilt(TreeNode* root) {
    traverse(root);
    return tilt;
  }
};