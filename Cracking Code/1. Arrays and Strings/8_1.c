#include <stdio.h>
#include <string.h>

int test_rotation(char *s1, char *s2){
	int i, j, len1, len2;
	if(!s1 || !s2) return 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if(len1 != len2) return 0;
	memcpy(s1 + len1, s1, sizeof(char) * len1);
	return strstr(s1, s2) != NULL;
}

int main(){
	char s1[100] = {0}, s2[100] = {0};
	while(1){
		gets(s1); gets(s2);
		printf("%d\n", test_rotation(s1, s2));
	}
	return 0;
}