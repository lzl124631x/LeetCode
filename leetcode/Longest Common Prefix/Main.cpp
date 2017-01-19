#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Longest Common Prefix.cpp"

#include <vector>
#include <string>
int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		int n = 0;
		RD(n);
		vector<string> v;
		string str;
		while(n--){
			cin >> str;
			v.push_back(str);
		}
		PRINTCASE;
		CLK_START;
		cout << s.longestCommonPrefix(v) << endl;
		CLK_END;
	}
	
	return 0;
}