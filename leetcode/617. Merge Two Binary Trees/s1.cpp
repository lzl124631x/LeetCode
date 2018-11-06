// OJ: https://leetcode.com/problems/merge-two-binary-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 || !t2) return t1 ? t1 : t2;
    TreeNode *node = new TreeNode(t1->val + t2->val);
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);
    return node;
  }
};