// OJ: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int postorder(TreeNode *root, long long sum, int limit) {
        if (!root) return 0;
        sum += root->val;
        int left = postorder(root->left, sum, limit);
        int right = postorder(root->right, sum, limit);
        if (sum + left < limit) root->left = NULL;
        if (sum + right < limit) root->right = NULL;
        return root->val + max(left, right);
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return postorder(root, 0, limit) < limit ? NULL : root;
    }
};