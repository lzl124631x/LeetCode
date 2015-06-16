#include <algorithm>
using namespace std;
// Input is guaranteed to be within the range from 1 to 3999.
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        char d[] = "IVXLCDM";
        char *p = d, d1, d5, d10;
        int a, b;
        while(num){
        	d1 = *p++;
        	d5 = *p++;
        	d10 = *p;
        	a = num % 10;
            b = a % 5;
        	if(b < 4){
        		for(int i = 0; i < b; ++i) ret += d1;
                if(a >= 5) ret += d5;
        	}else{
        		if(a == 9){
        			ret += d10;
        		}else{
        			ret += d5;
        		}
        		ret += d1;
        	}
        	num /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};