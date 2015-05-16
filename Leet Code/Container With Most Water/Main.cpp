#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Container With Most Water.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		vector<int> v = scanVector();
		PRINTCASE;
		CLK_START;
		cout << s.maxArea(v) << endl;
		CLK_END;
	}
	
	return 0;
}