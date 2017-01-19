#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Gray Code - 3.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		int n;
		cin >> n;
		PRINTCASE;
		CLK_START;
		printVector<int>(s.grayCode(n));
		CLK_END;
	}
	
	return 0;
}