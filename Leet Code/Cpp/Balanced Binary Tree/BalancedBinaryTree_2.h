#include "../+Helper/BinaryTree.h"

class Solution {
private:
    bool isBalanced(TreeNode *root, int &depth){
    	if(!root){
    		depth = 0;
    		return true;
    	}
        int dl = 0, dr = 0;
        if(!isBalanced(root->left, dl) || !isBalanced(root->right, dr))
        	return false;
        depth = 1 + max(dl, dr);
        return dl - dr <= 1 && dl - dr >= -1;
    }
public:
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
};