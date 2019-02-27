// OJ: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int ans = 0;
    void preorder(TreeNode *node, TreeNode *parent, int length) {
        if (!node) return;
        length = parent && parent->val + 1 == node->val ? length + 1 : 1;
        ans = max(ans, length);
        preorder(node->left, node, length);
        preorder(node->right, node, length);
    }
public:
    int longestConsecutive(TreeNode* root) {
        preorder(root, NULL, 0);
        return ans;
    }
};