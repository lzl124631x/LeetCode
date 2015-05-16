#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "../+Helper/BinaryTree.h"

TreeNode* insertData(TreeNode *root, int data){
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

TreeNode* balanceTree(TreeNode *root){
	
	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	TreeNode *root = NULL;
	for(int i = 0; i < num.size(); ++i){
		TreeNode* node = insertData(root, num[i]);
		root = balanceTree(root);
	}
	return root;
}

int main(){
	freopen("4_in.txt", "r", stdin);
	CLK_INIT;
	CASET{
		vector<int> v = scanVector();
		PRINTCASE;
		CLK_START;
		cout << serialize(sortedArrayToBST(v)) << endl;
		CLK_END;
	}
	
	return 0;
}