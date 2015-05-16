#include <stdio.h>
#include <iostream>
using namespace std;
#include "../+Helper/Helper.h"
#include "Divide Two Integers.h"

int main(){
	freopen("in.txt", "r", stdin);
	Solution s;
	cout << ((int)-2147483648) << endl;
	CASET{
		int a, b;
		cin >> a >> b;
		PRINTCASE;
		cout << s.divide(a, b) << endl;
	}
	return 0;
}