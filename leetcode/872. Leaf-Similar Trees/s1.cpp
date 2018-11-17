// OJ: https://leetcode.com/problems/leaf-similar-trees/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    void dfs(TreeNode *root, vector<int> &v) {
        if (!root) return;
        if (!root->left && !root->right) v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return a == b;
    }
};