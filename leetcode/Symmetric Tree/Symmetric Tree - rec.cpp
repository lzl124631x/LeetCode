class Solution {
public:
    bool isSymmetric(TreeNode *r1, TreeNode *r2){
        if(!r1 && !r2) return true;
        if(r1 && r2 && r1->val == r2->val) return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
        return false;
    }
    
    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
    }
};