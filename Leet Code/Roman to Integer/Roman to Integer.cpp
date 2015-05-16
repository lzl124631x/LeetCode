#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0, i = 0;
        char last = '\0';
        while(i < s.size()){
        	switch(s[i]){
        		case 'M': 
        			if(last == 'C') ret -= 200;
        			ret += 1000;
        			break;
        		case 'D':
        			if(last == 'C') ret -= 200;
        			ret += 500;
        			break;
        		case 'C':
        			if(last == 'X') ret -= 20; 
        			ret += 100;
        			break;
        		case 'L':
        			if(last == 'X') ret -= 20;
        			ret += 50;
        			break;
        		case 'X':
        			if(last == 'I') ret -= 2;
        			ret += 10;
        			break;
        		case 'V':
        			if(last == 'I') ret -=2;
        			ret += 5;
        			break;
        		case 'I':
        			ret += 1;
        			break;
        	}
        	last = s[i++];
        }
        return ret;
    }
};