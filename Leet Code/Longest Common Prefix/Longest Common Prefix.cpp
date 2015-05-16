#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int size = strs.size();
        if(size == 0) return "";
        if(size == 1) return strs[0];
        int cnt = 0;
        while(true){
            for(int i = 1; i < size; ++i){
                if(!strs[i][cnt] || strs[i][cnt] != strs[0][cnt]){
                    return string(strs[0], 0, cnt);
                }
            }
            cnt++;
        }
    }
};