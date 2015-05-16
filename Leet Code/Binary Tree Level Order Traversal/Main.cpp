#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Binary Tree Level Order Traversal.h"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string str;
		cin >> str;
		TreeNode *root = deserialize(str);
		PRINTCASE_;
		CLK_START;
		printVector(s.levelOrder(root));
		CLK_END;
	}
	
	return 0;
}