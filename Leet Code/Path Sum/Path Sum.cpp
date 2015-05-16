#include "../+Helper/BinaryTree.h"

class Solution {
public:
    bool preorder(TreeNode *root, int sum, int cur){
        if(!root) return false;
        cur += root->val;
        if(!root->left && !root->right && cur == sum) return true;
        return preorder(root->left, sum, cur) || preorder(root->right, sum, cur);
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        return preorder(root, sum, 0);
    }
};