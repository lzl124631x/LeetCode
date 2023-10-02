// OJ: https://leetcode.com/problems/closest-binary-search-tree-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
// Ref: https://leetcode.com/problems/closest-binary-search-tree-value/discuss/70331/Clean-and-concise-java-solution
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        while (root) {
            if (abs(target - root->val) < abs(target - ans)) ans = root->val;
            root = root->val > target ? root->left : root->right;
        }
        return ans;
    }
};