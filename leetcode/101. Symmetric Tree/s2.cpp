// OJ: https://leetcode.com/problems/symmetric-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root); q.push(root);
    while (q.size()) {
      TreeNode *a = q.front(); q.pop();
      TreeNode *b = q.front(); q.pop();
      if (!a && !b) continue;
      if (!a || !b || a->val != b->val) return false;
      q.push(a->left); q.push(b->right);
      q.push(a->right); q.push(b->left);
    }
    return true;
  }
};