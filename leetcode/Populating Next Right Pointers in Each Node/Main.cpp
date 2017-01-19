#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Populating Next Right Pointers in Each Node.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string str;
		cin >> str;
		TreeLinkNode *root = deserialize(str);
		PRINTCASE;
		CLK_START;
		s.connect(root);
		cout << serialize(root) << endl;
		CLK_END;
	}
	
	return 0;
}