#ifndef Helper_h
#define Helper_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include "BinaryTree.h"
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define PRINTCASE printf("Case #%d: ",case_n++)
#define PRINTCASE_ printf("Case #%d:\n",case_n++)
#define RD(a) scanf("%d", &(a))
#define RDD(a, b) scanf("%d%d", &(a), &(b))

#define CLK_INIT clock_t clk_start = 0, clk_end = 0
#define CLK_START clk_start = clock()
#define CLK_END\
	do{ clk_end = clock();\
	cout << "Time[" << (double)(clk_end - clk_start) / CLOCKS_PER_SEC << "s]" << endl; }while(0)

template<typename T>
void printVector(vector<T> v){
	typename vector<T>::iterator i = v.begin();
	for(; i != v.end(); ++i){
		cout << "[" << *i << "] ";
	}
	cout << endl;
}

template<typename T>
void printVector(vector<vector<T> > v){
	for(int i = 0; i < v.size(); ++i){
		for(int j = 0; j < v[i].size(); ++j){
			cout << "[" << v[i][j] << "] ";
		}
		cout << endl;
	}
}

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

vector<int> scanVector(){
	vector<int> v;
	string str;
	cin >> str;
	char *s = (char*) str.c_str(), *p = NULL;
	while(p = strsep(&s, ",")){
		v.push_back(atoi(p));
	}
	return v;
}

#endif