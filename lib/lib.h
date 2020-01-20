#ifndef lib_h
#define lib_h

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <unordered_set>
#include "codec.h"
#include "binary-tree.h"
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

#endif