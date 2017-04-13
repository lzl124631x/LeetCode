// OJ: https://leetcode.com/problems/find-bottom-left-tree-value
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int ans = 0;
    while (q.size()) {
      ans = q.front()->val;
      int N = q.size();
      while (N--) {
        root = q.front();
        q.pop();
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }
    return ans;
  }
};