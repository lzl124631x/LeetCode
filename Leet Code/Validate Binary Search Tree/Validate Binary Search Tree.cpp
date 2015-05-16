#include "../+Helper/BinaryTree.h"

class Solution {
public:
    bool recursiveTest(TreeNode *root, TreeNode *LB, TreeNode *RB){
        if(!root) return true;
        if(LB && root->val <= LB->val) return false;
        if(RB && root->val >= RB->val) return false;
        return recursiveTest(root->left, LB, root) && recursiveTest(root->right, root, RB);
    }
    bool isValidBST(TreeNode *root) {
        return recursiveTest(root, NULL, NULL);
    }
};