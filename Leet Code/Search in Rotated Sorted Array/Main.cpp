#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Search in Rotated Sorted Array - binary.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		int n, *A, t;
		cin >> n;
		A = new int[n];
		for(int i = 0; i < n; ++i) cin >> A[i];
		cin >> t;
		PRINTCASE;
		CLK_START;
		cout << s.search(A, n, t) << endl;
		CLK_END;
	}
	
	return 0;
}