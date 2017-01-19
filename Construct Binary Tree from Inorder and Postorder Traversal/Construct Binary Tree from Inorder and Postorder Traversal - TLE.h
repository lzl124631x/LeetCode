#include "../+Helper/BinaryTree.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = NULL;
        vector<int>::reverse_iterator post = postorder.rbegin();
        for(; post != postorder.rend(); ++post){
        	TreeNode *n = new TreeNode(*post);
        	if(!root){
        		root = n;
        	}else{
        		vector<int>::iterator i = find(inorder.begin(), inorder.end(),
        			n->val);
        		vector<int>::iterator start = inorder.begin(), end = inorder.end();
        		TreeNode *pnode = root;
        		while(true){
        			vector<int>::iterator p = find(start, end, pnode->val);
        			if(i > p){
        				if(pnode->right){
        					pnode = pnode->right;
        					start = p + 1;
        				}else{
        					pnode->right = n;
        					break;
        				}
        			}else{
        				if(pnode->left){
        					pnode = pnode->left;
        					end = p - 1;
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