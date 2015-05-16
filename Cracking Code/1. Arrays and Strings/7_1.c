#include <stdio.h>

#define MAX_N 100
#define MAX_M MAX_N
void clear_row_col(int mtx[][MAX_N], size_t M, size_t N){
	int i, j;
	int row[MAX_M] = {0}, col[MAX_N] = {0};
	if(!mtx) return;
	for(i = 0; i < M; ++i){
		for(j = 0; j < N; ++j){
			if(!mtx[i][j]) row[i] = col[j] = 1;
		}
	}
	for(i = 0; i < M; ++i){
		for(j = 0; j < N; ++j){
			if(row[i] || col[j]) mtx[i][j] = 0;
		}
	}
}

int main(){
	int mtx[MAX_M][MAX_N] = {0};
	size_t M = 0, N = 0;
	int i, j;
	while(1){
		scanf("%u%u", &M, &N);
		for(i = 0; i < M; ++i){
			for(j = 0; j < N; ++j){
				scanf("%d", &mtx[i][j]);
			}
		}
		clear_row_col(mtx, M, N);
		for(i = 0; i < M; ++i){
			for(j = 0; j < N; ++j){
				printf("%d ", mtx[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}