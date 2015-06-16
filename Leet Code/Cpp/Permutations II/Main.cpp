#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Permutations II.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		vector<int> v = scanVector();
		PRINTCASE_;
		CLK_START;
		printVector<int>(s.permuteUnique(v));
		CLK_END;
	}
	
	return 0;
}