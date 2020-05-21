// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int i = 0;
    int inorder(TreeNode *root, int k) {
        if (!root) return 0;
        int val = inorder(root->left, k);
        if (val) return val;
        if (++i == k) return root->val;
        return inorder(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};