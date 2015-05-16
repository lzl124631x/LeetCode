#include <stdio.h>
#include <string.h>

void remove_duplicate_char(char *str){
	int i, j, len;
	if(!str) return;
	len = strlen(str);
	i = 0;
	while(i < len){
		for(j = i + 1; j < len; ++j){
			if(str[i] == str[j]) str[j] = 0;
		}
		while(!str[++i]);
	}
	for(i = j = 0; j < len; j++){
		if(str[j]) str[i++] = str[j];
	}
	str[i] = 0;
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