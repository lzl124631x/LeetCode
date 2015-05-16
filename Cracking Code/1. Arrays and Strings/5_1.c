#include <stdio.h>
#include <string.h>

static void replace_space(char *s){
	int sp_cnt = 0, i, j;
	if(!s) return;
	for(i = 0; s[i]; ++i){
		if(s[i] == ' ') sp_cnt++;
	}
	j = i + (sp_cnt << 1);
	while(i >= 0){
		if(s[i] == ' '){
			s[j--] = '0';
			s[j--] = '2';
			s[j--] = '%';
		}else{
			s[j--] = s[i];
		}
		i--;
	}
}

int main(){
	char s[100] = {0};
	while(1){
		gets(s);
		replace_space(s);
		puts(s);
	}
	return 0;
}