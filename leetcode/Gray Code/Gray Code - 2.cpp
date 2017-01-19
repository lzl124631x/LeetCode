#include <vector>
using namespace std;

#define TOGGLE(val, n) ((val) ^ (1 << n))
class Solution {
public:
    int grayCode(int n, int val, vector<int> &v){
        if(n < 0) return val;
        val = grayCode(n - 1, val, v);
        val = TOGGLE(val, n);
        v.push_back(val);
        return grayCode(n - 1, val, v);
    }
    vector<int> grayCode(int n) {
        vector<int> v;
        if(n < 0) return v;
        v.push_back(0);
        grayCode(n - 1, 0, v);
        return v;
    }
};