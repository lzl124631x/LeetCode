// OJ: https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
private:
    vector<int> ans;
    bool dfs(TreeNode* root, vector<int>& voyage, int &i) {
        if (!root) return true;
        if (root->val != voyage[i]) return false;
        ++i;
        if (root->left && root->left->val != voyage[i]) {
            ans.push_back(root->val);
            return dfs(root->right, voyage, i) && dfs(root->left, voyage, i);
        }
        return dfs(root->left, voyage, i) && dfs(root->right, voyage, i);
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i = 0;
        if (dfs(root, voyage, i)) return ans;
        return { - 1 };
    }
};