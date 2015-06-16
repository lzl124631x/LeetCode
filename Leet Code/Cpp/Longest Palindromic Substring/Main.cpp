#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Longest Palindromic Substring.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		string str;
		cin >> str;
		PRINTCASE;
		CLK_START;
		cout << s.longestPalindrome(str) << endl;
		CLK_END;
	}
	
	return 0;
}