#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Letter Combinations of a Phone Number.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string str;
		cin >> str;
		PRINTCASE_;
		CLK_START;
		printVector<string>(s.letterCombinations(str));
		CLK_END;
	}
	
	return 0;
}