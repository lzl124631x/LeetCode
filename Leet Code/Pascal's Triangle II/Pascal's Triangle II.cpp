#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0) return vector<int>();
        vector<int> v(rowIndex + 1, 1);
        unsigned long long val = 1, a = rowIndex, b = 1;
        for(int i = 1; i <= rowIndex; ++i){
            val *= a--;
            val /= b++;
            v[i] = val;
        }
        return v;
    }
};