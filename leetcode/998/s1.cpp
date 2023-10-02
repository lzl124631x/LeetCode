// OJ: https://leetcode.com/problems/maximum-binary-tree-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *node = root, *prev = NULL;
        while (node && val < node->val) {
            prev = node;
            node = node->right;
        }
        auto n = new TreeNode(val);
        if (prev) prev->right = n;
        else root = n;
        n->left = node;
        return root;
    }
};