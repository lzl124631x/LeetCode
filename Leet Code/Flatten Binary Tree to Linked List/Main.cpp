#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Flatten Binary Tree to Linked List.h"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string str;
		cin >> str;
		TreeNode *root = deserialize(str);
		PRINTCASE;
		CLK_START;
		s.flatten(root);
		cout << serialize(root) << endl;
		CLK_END;
	}
	
	return 0;
}