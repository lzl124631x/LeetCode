// OJ: https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int ans = 0;
    int postorder(TreeNode *root) {
        if (!root) return 0;
        int move = 1 - root->val + postorder(root->left) + postorder(root->right);
        ans += abs(move);
        return move;
    }
public:
    int distributeCoins(TreeNode* root) {
        postorder(root);
        return ans;
    }
};