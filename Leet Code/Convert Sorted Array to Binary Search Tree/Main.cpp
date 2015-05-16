#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Convert Sorted Array to Binary Search Tree.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		vector<int> v = scanVector();
		PRINTCASE;
		CLK_START;
		cout << serialize(s.sortedArrayToBST(v)) << endl;
		CLK_END;
	}
	
	return 0;
}