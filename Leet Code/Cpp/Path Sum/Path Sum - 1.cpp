class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        sum -= root->val;
        if(!root->left && !root->right && !sum) return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};