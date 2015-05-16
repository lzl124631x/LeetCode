#include <vector>
using namespace std;

#define TOGGLE(val, n) ((val) ^ (1 << n))
class Solution {
public:
    void grayCode(int n, int &val, vector<int> &v){
        if(n < 0) return;
        grayCode(n - 1, val, v);
        val = TOGGLE(val, n);
        v.push_back(val);
        grayCode(n - 1, val, v);
    }
    vector<int> grayCode(int n) {
        vector<int> v;
        if(n < 0) return v;
        int val = 0;
        v.push_back(val);
        grayCode(n - 1, val, v);
        return v;
    }
};