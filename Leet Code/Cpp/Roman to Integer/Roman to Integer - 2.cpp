#include <string>
#include <unordered_map>
using namespace std;

// unordered_map is in the C++ 2011 standard.
// To enable the standard, you have to "g++ Main.cpp -std=c++11"
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, 
                                        {'D', 500}, {'M', 1000}};
        int ret = 0, i = s.size() - 1, last = 0;
        while(i >= 0){
            int cur = m[s[i--]];
            if(cur < last){
                ret -= cur;
            }else{
                ret += cur;
            }
            last = cur;
        }
        return ret;
    }
};