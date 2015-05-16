#include <stdio.h>
#include <string.h>

static void replace_space(char *src, char *dst){
	if(!src || !dst) return;
	while(*src){
		if(*src == ' '){
			*dst++ = '%';
			*dst++ = '2';
			*dst++ = '0';
		}else{
			*dst++ = *src;
		}
		src++;
	}
	*dst = 0;
}

int main(){
	char src[100] = {0}, dst[100] = {0};
	while(1){
		gets(src);
		replace_space(src, dst);
		puts(dst);
	}
	return 0;
}