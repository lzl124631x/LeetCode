class Solution {
private:
    vector<vector<int>> v;
    vector<int> path;
    void preorder(TreeNode *root, int sum) {
        if (!root) return;
        sum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && !sum) {
            v.push_back(path);
        } else {
            preorder(root->left, sum);
            preorder(root->right, sum);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        preorder(root, sum);
        return v;
    }
};