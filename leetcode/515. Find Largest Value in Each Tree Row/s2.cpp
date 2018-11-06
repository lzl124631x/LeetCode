// OJ: https://leetcode.com/problems/find-largest-value-in-each-tree-row
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  vector<int> ans;
  void preorder(TreeNode* root, int height) {
    if (!root) return;
    if (ans.size() < height) ans.push_back(root->val);
    else ans[height - 1] = max(ans[height - 1], root->val);
    preorder(root->left, height + 1);
    preorder(root->right, height + 1);
  }
public:
  vector<int> largestValues(TreeNode* root) {
    preorder(root, 1);
    return ans;
  }
};