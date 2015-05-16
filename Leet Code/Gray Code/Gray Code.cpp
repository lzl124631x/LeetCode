#include <vector>
using namespace std;

#define TOGGLE(val, n) ((val) ^ (1 << n))
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        if(n < 0) return v;
        int b = 0, val = 0;
        v.push_back(val);
        while(b < n){
        	int cnt = 1 << b, p = b;
        	bool l2r = true;
        	while(cnt -- > 0){
        		val = TOGGLE(val, p);
        		v.push_back(val);
        		if(l2r){
        			if(p > 0) p--;
        			else{
        				p++; l2r = false;
        			}
        		}else{
        			if(p < b - 1) p++;
        			else{
        				p--; l2r = true;
        			}
        		}
        	}
        	b++;
        }
        return v;
    }
};