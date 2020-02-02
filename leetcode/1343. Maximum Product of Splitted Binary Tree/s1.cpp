// OJ: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    long long s = 0, mod = 1e9 + 7, ans = 0;
    int postorder(TreeNode *root) {
        if (!root) return 0;
        int sum = root->val + postorder(root->left) + postorder(root->right);
        if (s) ans = max(ans, sum * (s - sum));
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        s = postorder(root);
        postorder(root);
        return ans % mod;
    }
};