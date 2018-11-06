// OJ: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
// Ref: https://discuss.leetcode.com/topic/3296/my-recursive-java-code-with-o-n-time-and-o-n-space/3
class Solution {
private:
  int pInorder, pPostorder;
  TreeNode *build(vector<int> &inorder, vector<int> &postorder, TreeNode *end) {
    if (pPostorder < 0) return NULL;
    TreeNode *root = new TreeNode(postorder[pPostorder--]);
    if (inorder[pInorder] != root->val) root->right = build(inorder, postorder, root);
    --pInorder;
    if (!end || inorder[pInorder] != end->val) root->left = build(inorder, postorder, end);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    pInorder = inorder.size() - 1;
    pPostorder = postorder.size() - 1;
    return build(inorder, postorder, NULL);
  }
};