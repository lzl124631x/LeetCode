#define MATCH_CHAR(s, p) ((p) == '.' ? s : (s) == (p))
class Solution {
public:
    // s is the input string, p is the regular expression.
    bool isMatch(const char *s, const char *p) {
    	if(!s && !p) return true;
    	if(!s || !p) return false;
    	if(!*p) return !*s;
    	if(*(p + 1) == '*'){
    		bool ret = false;
    		while(!(ret = isMatch(s, p + 2)) && MATCH_CHAR(*s, *p)) s++;
    		return ret;
    	}else{
    		return MATCH_CHAR(*s, *p) && isMatch(s + 1, p + 1);
    	}
    }
};

/*
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/