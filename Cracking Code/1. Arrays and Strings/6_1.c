#include <stdio.h>

typedef int pixel;
#define MAX_N 100
void rotate_matrix(pixel mtx[][MAX_N], size_t N){
	int i, j; pixel tmp;
	if(!mtx) return;
	for(i = 0; i < (N >> 1); ++i){
		for(j = i; j < N - i - 1; ++j){
			tmp = mtx[i][j];
			mtx[i][j] = mtx[N - j - 1][i];
			mtx[N - j - 1][i] = mtx[N - i - 1][N - j - 1];
			mtx[N - i - 1][N - j - 1] = mtx[j][N - i - 1];
			mtx[j][N - i - 1] = tmp;
		}
	}
}

int main(){
	pixel mtx[MAX_N][MAX_N] = {0};
	size_t N = 0;
	int i, j;
	while(1){
		scanf("%u", &N);
		for(i = 0; i < N; ++i){
			for(j = 0; j < N; ++j){
				scanf("%d", &mtx[i][j]);
			}
		}
		rotate_matrix(mtx, N);
		for(i = 0; i < N; ++i){
			for(j = 0; j < N; ++j){
				printf("%d ", mtx[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}