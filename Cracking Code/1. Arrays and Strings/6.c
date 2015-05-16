#include <stdio.h>

typedef int pixel;
#define AT(mtx, N, i, j) ((mtx)[(i) * (N) + (j)])
void rotate_matrix(pixel *mtx, size_t N){
	int i, j; pixel tmp;
	if(!mtx) return;
	for(i = 0; i < (N >> 1); ++i){
		for(j = i; j < N - i - 1; ++j){
			tmp = AT(mtx, N, i, j);
			AT(mtx, N, i, j) = AT(mtx, N, N - j - 1, i);
			AT(mtx, N, N - j - 1, i) = AT(mtx, N, N - i - 1, N - j - 1);
			AT(mtx, N, N - i - 1, N - j - 1) = AT(mtx, N, j, N - i - 1);
			AT(mtx, N, j, N - i - 1) = tmp;
		}
	}
}

#define MAX_NxN 100
int main(){
	pixel mtx[MAX_NxN] = {0};
	size_t N = 0;
	int i;
	while(1){
		scanf("%u", &N);
		for(i = 0; i < N * N; ++i){
			scanf("%d", &mtx[i]);
		}
		rotate_matrix(mtx, N);
		for(i = 0; i < N * N; ++i){
			printf("%d ", mtx[i]);
			if((i + 1) % N == 0) 
				printf("\n");
		}
	}
	return 0;
}