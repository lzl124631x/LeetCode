// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode *prev = NULL;
    while (!s.empty()) {
      root = s.top();
      s.pop();
      if (prev) {
        prev->left = NULL;
        prev->right = root;
      }
      prev = root;
      if (root->right) s.push(root->right);
      if (root->left) s.push(root->left);
    }
  }
};