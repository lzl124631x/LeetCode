// OJ: https://leetcode.com/problems/find-leaves-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    bool dfs(TreeNode *root, vector<int> &v) {
        if (!root) return true;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return true;
        }
        if (dfs(root->left, v)) root->left = NULL;
        if (dfs(root->right, v)) root->right = NULL;
        return false;
    }
    vector<int> removeLeaves(TreeNode *root) {
        vector<int> v;
        dfs(root, v);
        return v;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        while (root->left || root->right) {
            ans.push_back(removeLeaves(root));
        }
        ans.push_back({ root->val });
        return ans;
    }
};