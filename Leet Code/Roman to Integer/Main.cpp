#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Roman to Integer - 2.cpp"

#include <vector>
#include <string>
int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string rm;
		cin >> rm;
		PRINTCASE;
		CLK_START;
		cout << s.romanToInt(rm) << endl;
		CLK_END;
	}
	
	return 0;
}