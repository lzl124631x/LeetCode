#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "ZigZag Conversion.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string str; int nRows;
		cin >> str >> nRows;
		PRINTCASE;
		CLK_START;
		cout << s.convert(str, nRows) << endl;
		CLK_END;
	}
	
	return 0;
}