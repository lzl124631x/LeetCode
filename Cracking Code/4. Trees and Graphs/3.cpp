#include "../+Helper/BinaryTree.h"
#include <vector>
using namespace std;

class Solution{
public:
	TreeNode* buildBST(vector<int> v){
		TreeNode *root = NULL;
		vector<int>::iterator i = v.begin();
		for(; i != v.end(); ++i){
			TreeNode *n = new TreeNode(*i);
			if(!root){
				root = n;
			}else{
				TreeNode *p = root;
				while(true){
					if(n->val > p->val){
						if(p->right){
							p = p->right;
						}else{
							p->right = n;
							break;
						}
					}else if(n->val < p->val){
						if(p->left){
							p = p->left;
						}else{
							p->left = n;
							break;
						}
					}else{
						delete n;
					}
				}
			}
		}
		return root;
	}
};