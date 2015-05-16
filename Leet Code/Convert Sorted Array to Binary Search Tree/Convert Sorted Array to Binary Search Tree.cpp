#include "../+Helper/BinaryTree.h"
#include <vector>
using namespace std;

class Solution {
public:
	TreeNode *insertData(TreeNode *root, int data){
		TreeNode *node = new TreeNode(data);
		while(root){
			if(data > root->val){
				if(root->right){
					root = root->right;
				}else{
					root->right = node;
					root = NULL;
				}
			}else{
				if(root->left){
					root = root->left;
				}else{
					root->left = node;
					root = NULL;
				}
			}
		}
		return node;
	}

	TreeNode *recursiveInsert(TreeNode *root, vector<int> &num, int L, int R){
		if(L >= R) return NULL;
		int mid = (L + R) / 2;
		TreeNode *node = insertData(root, num[mid]);
		recursiveInsert(node, num, L, mid);
		recursiveInsert(node, num, mid + 1, R);
		return node;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return recursiveInsert(NULL, num, 0, num.size());
    }
};