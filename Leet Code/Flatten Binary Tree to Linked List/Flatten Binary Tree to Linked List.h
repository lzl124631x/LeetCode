#include "../+Helper/BinaryTree.h"
#include <stack>

class Solution {
public:
    void flatten(TreeNode *root) {
    	if(!root) return;
    	TreeNode *pnode = NULL;
    	stack<TreeNode*> s;
    	s.push(root);
    	while(!s.empty()){
    		root = s.top(); s.pop();
    		if(pnode){
    			pnode->left = NULL;
    			pnode->right = root;
    		}
    		if(root->right) s.push(root->right);
    		if(root->left) s.push(root->left);
    		pnode = root;
    	}
    	pnode->left = pnode->right = NULL;
    }
};