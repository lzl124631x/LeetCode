class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while(true){
            char *p = haystack, *q = needle;
            while(*p && *q && *p == *q){
                p++; q++;
            }
            if(!*q){
                return haystack;
            }else if(*p){
                haystack++;
            }else{
                return NULL;
            }
        }
    }
};