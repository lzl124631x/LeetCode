#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Construct Binary Tree from Inorder and Postorder Traversal - TLE.h"

#include <vector>
#include <string.h>
vector<int> parseVector(string str){
	vector<int> v;
	char *s = (char*)str.c_str(), *p = NULL;
	while(p = strsep(&s, ",")){
		v.push_back(atoi(p));
	}
	return v;
}

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string in, post;
		cin >> in >> post;
		vector<int> inv = parseVector(in), postv = parseVector(post);
		PRINTCASE;
		CLK_START;
		TreeNode *root = s.buildTree(inv, postv);
		cout << serialize(root) << endl;
		CLK_END;
	}
	
	return 0;
}