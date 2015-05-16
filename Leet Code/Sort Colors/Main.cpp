#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Sort Colors.cpp"

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		vector<int> v = scanVector();
		int *A = new int[v.size()];
		for(int i = 0; i < v.size(); ++i) A[i] = v[i];
		PRINTCASE;
		CLK_START;
		s.sortColors(A, v.size());
		for(int i = 0; i < v.size(); ++i) cout << A[i] << " ";
		cout << endl;
		CLK_END;
		delete A;
	}
	
	return 0;
}