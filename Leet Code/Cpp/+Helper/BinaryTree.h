#ifndef BinaryTree_h
#define BinaryTree_h
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> breathFirstTraversal(TreeNode *root){
	if(!root) return vector<int>();
	vector<int> v;
	queue<TreeNode*> q;
	q.push(root);
	int num = 1;
	while(num){
		int nextNum = 0;
		while(num--){
			TreeNode *n = q.front(); q.pop();
			v.push_back(n->val);
			if(n->left){
				nextNum++;
				q.push(n->left);
			}
			if(n->right){
				nextNum++;
				q.push(n->right);
			}
		}
		num = nextNum;
	}
	return v;
}

// Note: Invalid input is not considered yet.
TreeNode* deserialize(string str){
	char *s = (char*)str.c_str(), *p = strtok(s, ",");
	if(!strcmp(p, "#")) return NULL;
	TreeNode *root = new TreeNode(atoi(p));	
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *pnode = q.front(); q.pop();
		TreeNode *n[2] = {NULL};
		for(int i = 0; s && i < 2; ++i){
			p = strtok(NULL, ",");
			if(strcmp(p, "#")){
				n[i] = new TreeNode(atoi(p));
				q.push(n[i]);
			}
		}
		pnode->left = n[0];
		pnode->right = n[1];
	}
	return root;
}

string serialize(TreeNode* root){
	if(!root) return "";
	char buf[100000] = {0}, *p = buf;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *n = q.front(); q.pop();
		if(n){
			p += sprintf(p, "%d,", n->val);
		}else{
			p += sprintf(p, "#,");
		}
		if(n){
			q.push(n->left);
			q.push(n->right);
		}
	}
	while(*(p - 1) == ',' && *(p - 2) == '#') p -= 2;
	*(p - 1) = '\0';
	return string(buf);
}
#endif