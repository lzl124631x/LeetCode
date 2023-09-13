// OJ: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    pair<int, int> postorder(TreeNode *root) {
        pair<int, int> r{root->val, root->val};
        bool isBST = true;
        if (root->left) {
            auto left = postorder(root->left);
            if (root->val <= left.second) isBST = false;
            r.second = max(left.second, root->val);
            r.first = min(left.first, root->val);
        }
        if (root->right) {
            auto right = postorder(root->right);
            if (root->val >= right.first) isBST = false;
            r.second = max(right.second, root->val);
            r.first = min(right.first, root->val);
        }
        root->val += (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        if (isBST) ans = max(ans, root->val);
        return isBST ? r :  pair<int,int>{ INT_MIN, INT_MAX };
    }
public:
    int maxSumBST(TreeNode* root) {
        if (!root) return 0;
        postorder(root);
        return ans;
    }
};