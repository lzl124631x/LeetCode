// OJ: https://leetcode.com/problems/binary-tree-tilt
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  int findTilt(TreeNode *root, int &sum) {
    if (!root) {
      sum = 0;
      return 0;
    }
    int leftSum = 0, rightSum = 0;
    int left = findTilt(root->left, leftSum);
    int right = findTilt(root->right, rightSum);
    sum = leftSum + rightSum + root->val;
    return left + right + abs(leftSum - rightSum);
  }
public:
  int findTilt(TreeNode* root) {
    int sum = 0;
    return findTilt(root, sum);
  }
};