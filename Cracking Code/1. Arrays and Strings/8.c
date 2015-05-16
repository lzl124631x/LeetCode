#include <stdio.h>
#include <string.h>

int test_rotation(char *s1, char *s2){
	int i, j, len1, len2;
	if(!s1 || !s2) return 0;
	i = j = 0;
	while(s2[j] && s2[j] != s1[0]) j++;
	while(s1[i] && s2[j] && s1[i] == s2[j]){
		i++; j++;
	}
	if(s2[j]) return 0;
	len2 = j;
	j = 0;
	while(s1[i] && s2[j] && s1[i] == s2[j]){
		i++; j++;
	}
	if(s1[i]) return 0;
	len1 = i;
	return len1 == len2;
}

int main(){
	char s1[100] = {0}, s2[100] = {0};
	while(1){
		gets(s1); gets(s2);
		printf("%d\n", test_rotation(s1, s2));
	}
	return 0;
}