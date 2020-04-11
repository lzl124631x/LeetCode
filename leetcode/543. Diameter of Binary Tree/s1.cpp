// OJ: https://leetcode.com/problems/diameter-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
    int ans = 0;
    int postorder(TreeNode *root) {
        if (!root) return 0;
        int left = postorder(root->left), right = postorder(root->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        postorder(root);
        return ans;
    }
};