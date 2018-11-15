// OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(log(N))
// Space: O(log(N))
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        return val > root->val ? searchBST(root->right, val) : searchBST(root->left, val);
    }
};