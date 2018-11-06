// OJ: https://leetcode.com/problems/merge-two-binary-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
  TreeNode *copy(TreeNode *root) {
    if (!root) return NULL;
    TreeNode *node = new TreeNode(root->val);
    node->left = copy(root->left);
    node->right = copy(root->right);
    return node;
  }
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 || !t2) return t1 ? copy(t1) : copy(t2);
    TreeNode *node = new TreeNode(t1->val + t2->val);
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);
    return node;
  }
};