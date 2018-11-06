// OJ: https://leetcode.com/problems/symmetric-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
  bool isSymmetric(TreeNode *r1, TreeNode *r2) {
    return (!r1 && !r2)
    || (r1 && r2 && r1->val == r2->val && isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left));
  }
public:
  bool isSymmetric(TreeNode* root) {
    return isSymmetric(root, root);
  }
};