// OJ: https://leetcode.com/problems/diameter-of-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  int ans = 0;
  int maxDepth (TreeNode* root) {
    if (!root) return 0;
    int L = maxDepth(root->left), R = maxDepth(root->right);
    ans = max(ans, L + R);
    return 1 + max(L, R);
  }
public:
  int diameterOfBinaryTree(TreeNode* root) {
    maxDepth(root);
    return ans;
  }
};