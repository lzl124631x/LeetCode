#include <stdio.h>
#include <stdlib.h>

char* itoa(int value, char* result, int base) {
	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );

	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';

	*ptr-- = '\0';

	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}

	return result;
}

int interpose(int N, int M, int i, int j){
	return N & ~((1 << (j + 1)) - (1 << i)) | M << i;
}

int main(){
	int N, M, i, j;
	char str[100] = {0};
	N = 0xffff; M = 10; i = 3; j = 7;
	printf("i = %d, j = %d\n", i, j);
	printf("N = %s\n", itoa(N, str, 2));
	printf("M = %s\n", itoa(M, str, 2));
	printf("Result = %s\n", itoa(interpose(N, M, i, j), str, 2));
}