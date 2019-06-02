// OJ: https://leetcode.com/problems/binary-tree-paths/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<TreeNode*> v;
    vector<string> ans;
    string getString() {
        string s = to_string(v[0]->val);
        for (int i = 1; i < v.size(); ++i) {
            s += "->" + to_string(v[i]->val);
        }
        return s;
    }
    void preorder(TreeNode *root) {
        v.push_back(root);
        if (!root->left && !root->right) ans.push_back(getString());
        if (root->left) preorder(root->left);
        if (root->right) preorder(root->right);
        v.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        preorder(root);
        return ans;
    }
};