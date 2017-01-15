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
    vector<string> v;
    void dfs(TreeNode *root, string path) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            v.push_back(path);
            return;
        }
        path += "->";
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        dfs(root, "");
        return v;
    }
};