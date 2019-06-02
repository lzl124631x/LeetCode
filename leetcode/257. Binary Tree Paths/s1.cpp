// OJ: https://leetcode.com/problems/binary-tree-paths/
// Author: github.com/lzl124631x
// Time: O(NH)
// Space: O(H^2)
class Solution {
private:
    vector<string> v;
    void preorder(TreeNode *root, string path) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            v.push_back(path);
            return;
        }
        path += "->";
        if (root->left) preorder(root->left, path);
        if (root->right) preorder(root->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        preorder(root, "");
        return v;
    }
};