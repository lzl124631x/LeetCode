#define SKIP_SPACE(s) while(*s == ' ') s++;
#define SKIP_NON_SPACE(s) while(*s && *s != ' ') s++;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!s) return 0;
        char *begin = NULL, *end = NULL, *p = (char*)s;
        SKIP_SPACE(p);
        while(*p){
        	end = begin = p;
        	SKIP_NON_SPACE(end);
        	p = end;
        	SKIP_SPACE(p);
        }
        return (end - begin) / sizeof(char);
    }
};