// OJ: https://leetcode.com/problems/binary-tree-cameras/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    TreeNode *R;
    int postorder(TreeNode* root) {
        if (!root) return 0;
        int ans = postorder(root->left) + postorder(root->right);
        int left = root->left ? root->left->val : 1;
        int right = root->right ? root->right->val : 1;
        if (left == 0 || right == 0) {
            root->val = 2;
            return ans + 1;
        } else if (left == 2 || right == 2) {
            root->val = 1;
            return ans;
        } else return root == R ? ans + 1 : ans;
    }
public:
    int minCameraCover(TreeNode* root) {
        R = root;
        return postorder(root);
    }
};