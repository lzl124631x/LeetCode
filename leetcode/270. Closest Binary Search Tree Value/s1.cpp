// OJ: https://leetcode.com/problems/closest-binary-search-tree-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double dist = abs(target - root->val);
        if (dist < .5) return root->val;
        if (root->val < target) {
            if (!root->right) return root->val;
            int right = closestValue(root->right, target);
            return dist < abs(target - right) ? root->val : right;
        }
        if (!root->left) return root->val;
        int left = closestValue(root->left, target);
        return dist < abs(target - left) ? root->val : left;
    }
};