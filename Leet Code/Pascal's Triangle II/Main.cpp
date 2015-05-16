#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Pascal's Triangle II.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		int n;
		cin >> n;
		PRINTCASE_;
		CLK_START;
		printVector<int>(s.getRow(n));
		CLK_END;
	}
	
	return 0;
}