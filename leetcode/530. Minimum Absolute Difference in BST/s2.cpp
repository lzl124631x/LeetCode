// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
// Inorder traversal yields sorted sequence. We just need to 
// subtract the previous element from the current one, and keep
// track of the minimum.
// Ref: https://discuss.leetcode.com/topic/80836/c-7-lines-o-n-run-time-o-h-memory
class Solution {
private:
  int minVal = INT_MAX, prev = -1;
public:
  int getMinimumDifference(TreeNode* root) {
    if (!root) return INT_MAX;
    getMinimumDifference(root->left);
    if (prev != -1) minVal = min(minVal, root->val - prev);
    prev = root->val;
    getMinimumDifference(root->right);
    return minVal;
  }
};