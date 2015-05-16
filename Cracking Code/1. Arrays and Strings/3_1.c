#include <stdio.h>
#include <string.h>

void remove_duplicate_char(char *str){
	int i, j, tail, len;
	if(!str) return;
	len = strlen(str);
	tail = 1;
	for(i = 1; i < len; ++i){
		for(j = 0; j < tail; ++j){
			if(str[i] == str[j])
				break;
		}
		if(j == tail){
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
