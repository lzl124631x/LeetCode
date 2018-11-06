// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  TreeNode* helper(TreeNode *root) {
    if (!root) return NULL;
    auto leftEnd = helper(root->left), rightEnd = helper(root->right), right = root->right;
    root->right = root->left;
    root->left = NULL;
    if (leftEnd) leftEnd->right = right;
    else root->right = right;
    return rightEnd ? rightEnd : (leftEnd ? leftEnd : root);
  }
public:
  void flatten(TreeNode* root) {
    helper(root);
  }
};