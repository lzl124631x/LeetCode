#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Implement strStr().cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	char c = '\0';
	cout << "Case #0: " << boolalpha << (s.strStr(&c, &c) != NULL) << endl;
	CASET{
		string a, b;
		cin >> a >> b;
		PRINTCASE;
		CLK_START;
		cout << boolalpha << (s.strStr((char*)a.c_str(), (char*)b.c_str()) != NULL) << endl;
		CLK_END;
	}
	
	return 0;
}