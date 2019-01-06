// OJ: https://leetcode.com/problems/binary-tree-cameras/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    int ans = 0;
    int postorder(TreeNode *root) {
        if (!root) return 1;
        int left = postorder(root->left);
        int right = postorder(root->right);
        if (left == 0 || right == 0) {
            ++ans;
            return 2;
        } else return left == 2 || right == 2 ? 1 : 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        return postorder(root) == 0 ? ans + 1 : ans;
    }
};