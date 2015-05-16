#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(const char *s, int len){
        int i = 0, j = len - 1;
        while(i < j && s[i] == s[j]){
            i++; j--;
        }
        return i >= j;
    }
    
    string longestPalindrome(string s) {
        const char *str = s.c_str();
        int len = s.size(), L = len;
        while(L > 1){
            for(int i = 0; i <= len - L; ++i){
                if(isPalindrome(str + i, L))
                    return string(s, i, L);
            }
            --L;
        }
        return string(s, 0, L);
    }
};