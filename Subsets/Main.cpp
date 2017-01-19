#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Subsets.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		vector<int> v = scanVector();
		PRINTCASE;
		CLK_START;
		printVector<int>(s.subsets(v));
		CLK_END;
	}
	
	return 0;
}