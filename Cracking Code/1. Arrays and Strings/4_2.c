#include <stdio.h>
#include <string.h>

static int test_anagram(char *s1, char *s2){
	int dic[256] = {0};
	int len1, len2, i;
	if(!s1 || !s2) return 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if(len1 != len2) return 0;
	for(i = 0; i < len1; ++i){
		dic[s1[i]]++;
	}
	for(i = 0; i < len2; ++i){
		dic[s2[i]]--;
		if(dic[s2[i]] < 0) return 0;
	}
	return 1;
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