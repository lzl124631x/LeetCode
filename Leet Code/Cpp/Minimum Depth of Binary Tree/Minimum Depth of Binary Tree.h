#include "../+Helper/BinaryTree.h"
#include <queue>
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int n = 1, depth = 1;
        while(n){
        	int nextN = 0;
        	while(n--){
        		root = q.front(); q.pop();
        		if(!root->left && !root->right) return depth;
        		if(root->left){
        			nextN++;
        			q.push(root->left);
        		}
        		if(root->right){
        			nextN++;
        			q.push(root->right);
        		}
        	}
        	n = nextN;
        	depth++;
        }
    }
};