// OJ: https://leetcode.com/problems/find-largest-value-in-each-tree-row
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    queue<TreeNode*> q;
    if (root) q.push(root);
    int cnt = 1;
    vector<int> ans;
    while (q.size()) {
      int nextCnt = 0;
      int maxVal = INT_MIN;
      while (cnt--) {
        root = q.front();
        q.pop();
        if (root->left) { q.push(root->left); ++nextCnt; }
        if (root->right) { q.push(root->right); ++nextCnt; };
        maxVal = max(maxVal, root->val);
      }
      ans.push_back(maxVal);
      cnt = nextCnt;
    }
    return ans;
  }
};