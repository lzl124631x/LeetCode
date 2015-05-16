#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Validate Binary Search Tree.cpp"

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
		cout << boolalpha << s.isValidBST(root) << endl;
		CLK_END;
	}
	
	return 0;
}