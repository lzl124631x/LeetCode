// OJ: https://leetcode.com/problems/binary-tree-level-order-traversal-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    for (int cnt = 1; cnt; ) {
      int nextCnt = 0;
      vector<int> row;
      while (cnt--) {
        TreeNode *root = q.front();
        q.pop();
        row.push_back(root->val);
        if (root->left) {
          q.push(root->left);
          ++nextCnt;
        }
        if (root->right) {
          q.push(root->right);
          ++nextCnt;
        }
      }
      ans.push_back(row);
      cnt = nextCnt;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};