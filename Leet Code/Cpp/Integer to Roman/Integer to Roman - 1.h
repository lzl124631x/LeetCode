#include <algorithm>
using namespace std;
// Input is guaranteed to be within the range from 1 to 3999.
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        char d[] = "--MDCLXVI";
        char *p = d, d1, d5, d10;
        int a, b, base = 1000;
        while(num){
        	d10 = *p++;
        	d5 = *p++;
        	d1 = *p;
        	a = num / base;
            b = a % 5;
        	if(b < 4){
                if(a >= 5) ret += d5;
        		for(int i = 0; i < b; ++i) ret += d1;
        	}else{
                ret += d1;
        		if(a == 9){
        			ret += d10;
        		}else{
        			ret += d5;
        		}
        	}
        	num -= a * base;
            base /= 10;
        }
        return ret;
    }
};