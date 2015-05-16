#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        string ret;
        if(nRows <= 0) return ret;
        if(nRows == 1) return s;
        int length = s.size();
        int offset2 = (nRows - 1) * 2;
        for(int i = 0; i < nRows && i < length; ++i){
            int p = i;
            int offset1 = offset2 - i * 2;
            while(p < length){
                ret += s[p];
                if(offset1 && offset1 != offset2 && p + offset1 < length){
                    ret += s[p + offset1];
                }
                p += offset2;
            }
        }
        return ret;
    }
};