#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Count and Say.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		int n;
		cin >> n;
		PRINTCASE;
		CLK_START;
		cout << s.countAndSay(n) << endl;
		CLK_END;
	}
	
	return 0;
}