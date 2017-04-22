// OJ: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    bool ltr = true;
    vector<vector<int>> ans;
    while (q.size()) {
      int N = q.size();
      vector<int> lv;
      stack<TreeNode*> s;
      while (N--) {
        root = q.front();
        q.pop();
        lv.push_back(root->val);
        if (ltr) {
          if (root->left) s.push(root->left);
          if (root->right) s.push(root->right);
        } else {
          if (root->right) s.push(root->right);
          if (root->left) s.push(root->left);
        }
      }
      while (s.size()) { q.push(s.top()); s.pop(); }
      ltr = !ltr;
      ans.push_back(lv);
    }
    return ans;
  }
};