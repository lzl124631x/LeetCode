#include <stdio.h>
#include <iostream>
using namespace std;
#include "../+Helper/Helper.h"
#include "Integer to Roman - 1.h"

int main(){
	freopen("in.txt", "r", stdin);
	Solution s;
	CASET{
		int n;
		cin >> n;
		PRINTCASE;
		cout << s.intToRoman(n) << endl;
	}
	return 0;
}