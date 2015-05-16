#include <stdio.h>
#include <string.h>

void remove_duplicate_char(char *str){
	char hit[256] = {0};
	int i, tail = 0;
	if(!str) return;
	for(i = 0; str[i]; ++i){
		if(!hit[str[i]]){
			hit[str[i]] = 1;
			str[tail++] = str[i];
		}
	}
	str[tail] = 0;
}

int main(){
	char str[100] = {0};
	while(1){
		gets(str);
		remove_duplicate_char(str);
		puts(str);
	}
	return 0;
}