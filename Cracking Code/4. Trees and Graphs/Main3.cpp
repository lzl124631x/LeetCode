#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "3.cpp"

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
	freopen("3in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string in;
		cin >> in;
		PRINTCASE;
		CLK_START;
		TreeNode *root = s.buildBST(parseVector(in));
		cout << serialize(root) << endl;
		CLK_END;
	}
	
	return 0;
}