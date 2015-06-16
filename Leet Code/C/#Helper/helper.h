#ifndef helper_h
#define helper_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define PRINTCASE printf("Case #%d: ",case_n++)
#define PRINTCASE_ printf("Case #%d:\n",case_n++)
#define RD(a) scanf("%d", &(a))
#define RDD(a, b) scanf("%d%d", &(a), &(b))

#define CLK_INIT clock_t clk_start = 0, clk_end = 0
#define CLK_START clk_start = clock()
#define CLK_END\
	do{ clk_end = clock();\
    printf("Time[%.3lfs]\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);\
  } while (0)

#endif