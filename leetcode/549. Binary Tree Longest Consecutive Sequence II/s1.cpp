// OJ: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii
// Author: github.com/lzl124631x
// Time: O(N^2) (N is # of nodes)
// Space: O(H) (H is height of tree)
class Solution {
private:
  int longestConsecutive(TreeNode *root, TreeNode *p, bool increment) {
    if (!root) return 0;
    int ans = 0;
    if (root->val == (increment ? p->val + 1 : p->val - 1))
      ans = max(ans, max(1 + longestConsecutive(root->left, root, increment),
        1 + longestConsecutive(root->right, root, increment)));
    return ans;
  }
public:
  int longestConsecutive(TreeNode* root) {
    if (!root) return 0;
    int ans = 1;
    ans = max(ans, 1 + longestConsecutive(root->left, root, false) + longestConsecutive(root->right, root, true));
    ans = max(ans, 1 + longestConsecutive(root->left, root, true) + longestConsecutive(root->right, root, false));
    ans = max(ans, longestConsecutive(root->left));
    ans = max(ans, longestConsecutive(root->right));
    return ans;
  }
};