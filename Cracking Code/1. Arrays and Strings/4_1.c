#include <stdio.h>
#include <string.h>

void qsort(char *s, int low, int high){
	int i, j;
	char c;
	if(!s || low >= high) return;
	c = s[low];
	i = low; j = high;
	while(i < j){
		while(i < j && s[j] > c) --j;
		if(i < j) s[i++] = s[j];
		while(i < j && s[i] < c) ++i;
		if(i < j) s[j--] = s[i];
	}
	s[i] = c;
	qsort(s, low, i - 1);
	qsort(s, i + 1, high);
}

int test_anagram(char *s1, char *s2){
	int len1, len2;
	if(!s1 || !s2) return 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if(len1 != len2) return 0;
	qsort(s1, 0, len1 - 1);
	qsort(s2, 0, len2 - 1);
	return !strcmp(s1, s2);
}

int main(){
	char s1[100] = {0}, s2[100] = {0};
	while(1){
		gets(s1);
		gets(s2);
		printf("%d\n", test_anagram(s1, s2));
	}
	return 0;
}