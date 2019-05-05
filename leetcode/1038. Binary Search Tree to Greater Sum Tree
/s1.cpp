// OJ: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return NULL;
        bstToGst(root->right);
        root->val = (sum += root->val);
        bstToGst(root->left);
        return root;
    }
};