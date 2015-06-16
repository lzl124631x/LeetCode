#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0, i = s.size() - 1;
        while(i >= 0){
        	switch(s[i--]){
        		case 'M': ret += 1000; break;
        		case 'D': ret += 500; break;
        		case 'C': ret += ret >= 500 ? -100 : 100; break;
        		case 'L': ret += 50; break;
        		case 'X': ret += ret >= 50 ? -10 : 10; break;
        		case 'V': ret += 5; break;
        		case 'I': ret += ret >= 5 ? -1 : 1; break;
        	}
        }
        return ret;
    }
};