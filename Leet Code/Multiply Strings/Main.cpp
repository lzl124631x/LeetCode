#include <stdio.h>
#include <iostream>
using namespace std;
#include "../+Helper/Helper.h"
#include "Multiply Strings.h"

int main(){
	freopen("in.txt", "r", stdin);
	Solution s;
	CASET{
		string a, b;
		cin >> a >> b;
		PRINTCASE;
		cout << s.multiply(a, b) << endl;
	}
	return 0;
}