#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Regular Expression Matching.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string str, reg;
		cin >> str >> reg;
		PRINTCASE;
		CLK_START;
		cout << boolalpha << s.isMatch(str.c_str(), reg.c_str()) << endl;
		CLK_END;
	}
	
	return 0;
}