/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int ans = 0;
    void dfs(TreeNode *root, int sum) {
        if (!root) return;
        sum = 10 * sum + root->val;
        if (!root->left && !root->right) ans += sum;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};