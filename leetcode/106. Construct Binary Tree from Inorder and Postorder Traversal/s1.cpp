// OJ: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(logN)
class Solution {
private:
  TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int pi, int pe) {
    if (is > ie) return NULL;
    TreeNode *root = new TreeNode(postorder[pe]);
    int leftLen = find(inorder.begin() + is, inorder.begin() + ie, postorder[pe]) - inorder.begin() - is;
    root->left = buildTree(inorder, postorder, is, is + leftLen - 1, pi, pi + leftLen - 1);
    root->right = buildTree(inorder, postorder, is + leftLen + 1, ie, pi + leftLen, pe - 1);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }
};