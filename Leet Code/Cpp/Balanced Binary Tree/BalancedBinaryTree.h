#include "../+Helper/BinaryTree.h"

class Solution {
public:
	int depth(TreeNode *root){
		if(!root) return 0;
		int dl = depth(root->left), dr = depth(root->right);
		return 1 + max(dl, dr);
	}

    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        int dl = depth(root->left), dr = depth(root->right);
        if(dl - dr > 1 || dl - dr < -1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};