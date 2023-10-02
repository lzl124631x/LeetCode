// OJ: https://leetcode.com/problems/longest-happy-prefix/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
        string longestPrefix(string s) {
        int n = s.size();
        string_view sv = s;
        for(int len = n-1; len>=1; len--){
            if (sv.substr(0, len) == sv.substr(n-len))
                return s.substr(0, len);
        }
        return "";
    }
};