// Author: github.com/lzl124631x
// Time: O(N) where N is # of nodes.
// Space: O(1)
// The worst case should be where the tree is complete.
// Given the # of nodes is N, the height of tree (h) is about logN.
// There are 2^i nodes at level i (0 <= i <= h - 1), and each of which requires
// 2 * (h - i) operations.
// So # of operations S = 2^(h-1)*0 + 2^(h-2)*1 + ... + 2^0*(h-1) --- (1)
// 2S = 2^h*0 + 2^(h-1)*1 + ... + 2^1*(h-1) --- (2)
// (2) - (1): S = 2^h*0 + 2^(h-1) + 2^(h-2) + ... + 2^1 - 2^0*(h-1)
//              = 2(1-2^(h-1))/(1-2)-(h-1) = 2^h - h - 1
//              = N - logN - 1 <= N (N >= 1)
// So the time complexity is O(N)
class Solution {
private:
  TreeNode* getLargest(TreeNode* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
  }
  TreeNode* getSmallest(TreeNode* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
  }
public:
  int getMinimumDifference(TreeNode* root) {
    if (!root) return INT_MAX;
    TreeNode *left = getLargest(root->left), *right = getSmallest(root->right);
    int minVal = min(INT_MAX, min(getMinimumDifference(root->left), getMinimumDifference(root->right)));
    if (left) minVal = min(minVal, root->val - left->val);
    if (right) minVal = min(minVal, right->val - root->val);
    return minVal;
  }
};