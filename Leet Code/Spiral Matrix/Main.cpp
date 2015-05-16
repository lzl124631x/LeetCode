#include <iostream>
using namespace std;
#include <stdio.h>
#include <time.h>
#include "../+Helper/Helper.h"
#include "Spiral Matrix.cpp"

vector<vector<int> > scanVector(int m, int n){
	vector<vector<int> > v;
	for(int i = 0; i < m; ++i){
		vector<int> v1;
		for(int j = 0; j < n; ++j){
			int d;
			cin >> d;
			v1.push_back(d);
		}
		v.push_back(v1);
	}
	return v;
}

int main(){
	freopen("in.txt", "r", stdin);
	CLK_INIT;
	Solution s;
	CASET{
		int m, n;
		RDD(m, n);
		vector<vector<int> > v = scanVector(m, n);
		PRINTCASE_;
		CLK_START;
		printVector(s.spiralOrder(v));
		CLK_END;
	}
	
	return 0;
}