class Solution {
public:
    void preorder(TreeNode *root, int sum, vector<vector<int> > &v, vector<int> v1){
        if(!root) return;
        v1.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right && !sum){
            v.push_back(v1);
            return;
        }
        preorder(root->left, sum, v, v1);
        preorder(root->right, sum, v, v1);
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > v;
        if(!root) return v;
        preorder(root, sum, v, vector<int>());
    }
};