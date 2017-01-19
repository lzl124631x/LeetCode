#include "../+Helper/BinaryTree.h"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = NULL;
        map<TreeNode*, vector<int>::iterator> m;
        vector<int>::reverse_iterator post = postorder.rbegin();
        for(; post != postorder.rend(); ++post){
        	TreeNode *n = new TreeNode(*post);
            vector<int>::iterator i = find(inorder.begin(), inorder.end(), n->val);
            m[n] = i;
        	if(!root){
        		root = n;
        	}else{
        		TreeNode *pnode = root;
        		while(true){
        			if(i > m[pnode]){
        				if(pnode->right){
        					pnode = pnode->right;
        				}else{
        					pnode->right = n;
        					break;
        				}
        			}else{
        				if(pnode->left){
        					pnode = pnode->left;
        				}else{
        					pnode->left = n;
        					break;
        				}
        			}
        		}
        	}
        }
        return root;
    }
};