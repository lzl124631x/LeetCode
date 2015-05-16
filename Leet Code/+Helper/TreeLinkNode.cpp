#include <iostream>
#include <queue>
#include <string>
using namespace std;
#include <stdlib.h>
#include <string.h>

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// Note: Invalid input is not considered yet.
TreeLinkNode* deserialize(string str){
	char *s = (char*)str.c_str(), *p = NULL;
	p = strsep(&s, ",");
	if(!strcmp(p, "#")) return NULL;
	TreeLinkNode *root = new TreeLinkNode(atoi(p));	
	queue<TreeLinkNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeLinkNode *pnode = q.front(); q.pop();
		TreeLinkNode *n[2] = {NULL};
		for(int i = 0; s && i < 2; ++i){
			p = strsep(&s, ",");
			if(strcmp(p, "#")){
				n[i] = new TreeLinkNode(atoi(p));
				q.push(n[i]);
			}
		}
		pnode->left = n[0];
		pnode->right = n[1];
	}
	return root;
}

string serialize(TreeLinkNode* root){
	if(!root) return "";
	char buf[100000] = {0}, *p = buf;
	TreeLinkNode *nextLv = root;
	while(nextLv){
		root = nextLv;
		nextLv = NULL;
		while(root){
			p += sprintf(p, "%d,", root->val);
			if(!nextLv && (root->left || root->right)){
				nextLv = root->left ? root->left : root->right;
			}
			root = root->next;
		}
		*(p - 1) = '#';
	}
	*(p - 1) = '\0';
	return string(buf);
}