// OJ: https://leetcode.com/problems/convert-bst-to-greater-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  int sum = 0;
public:
  TreeNode* convertBST(TreeNode* root) {
    if (!root) return NULL;
    convertBST(root->right);
    sum = (root->val += sum);
    convertBST(root->left);
    return root;
  }
};