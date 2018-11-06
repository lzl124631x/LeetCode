// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  bool isValidBST(TreeNode *root, TreeNode *lb, TreeNode *rb) {
    if (!root) return true;
    if ((lb && root->val <= lb->val) || (rb && root->val >= rb->val)) return false;
    return isValidBST(root->left, lb, root) && isValidBST(root->right, root, rb);
  }
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
  }
};