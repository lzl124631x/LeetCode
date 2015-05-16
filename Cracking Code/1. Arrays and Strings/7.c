#include <stdio.h>

#define MAX_N 100
#define MAX_M MAX_N
void clear_row_col(int mtx[][MAX_N], size_t M, size_t N){
	int i, j; int first_row = 1, first_col = 1;
	if(!mtx) return;
	if(!mtx[0][0]){
		first_row = first_col = 0;
	}
	// set tag
	for(j = 1; j < N; ++j){
		if(!mtx[0][j]){
			first_row = 0;
			break;
		}
	}
	for(i = 1; i < M; ++i){
		if(!mtx[i][0]){
			first_col = 0;
			break;
		}
	}
	for(i = 1; i < M; ++i){
		for(j = 1; j < N; ++j){
			if(!mtx[i][j]){
				mtx[i][0] = mtx[0][j] = 0;
			}
		}
	}
	// clear row and column
	for(j = 1; j < N; ++j){
		if(!mtx[0][j]){
			for(i = 1; i < M; ++i) mtx[i][j] = 0;
		}
	}
	for(i = 1; i < M; ++i){
		if(!mtx[i][0]){
			for(j = 1; j < N; ++j) mtx[i][j] = 0;
		}
	}
	if(!first_row){
		for(j = 0; j < N; ++j) mtx[0][j] = 0;
	}
	if(!first_col){
		for(i = 0; i < M; ++i) mtx[i][0] = 0;
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