#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if(numRows <= 0) return vector<vector<int> >();
        vector<vector<int> > v(numRows, vector<int>(1, 1));
        for(int n = 1; n < numRows; ++n){
            vector<int> &v1 = v[n], v0 = v[n - 1];
            for(int i = 1; i < n; ++i){
                v1.push_back(v0[i - 1] + v0[i]);
            }
            v1.push_back(1);
        }
        return v;
    }
};