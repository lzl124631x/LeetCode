// OJ: https://leetcode.com/problems/html-entity-parser/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string entityParser(string s) {
        int N = s.size(), i = 0;
        string ans;
        while (i < N) {
            if (s[i] != '&') ans += s[i++];
            else {
                string ent;
                do {
                    ent += s[i++];
                } while (i < N && s[i - 1] != ';');
                if (ent == "&quot;") ans += "\""; 
                else if (ent == "&apos;" ) ans += "\'"; 
                else if (ent == "&amp;" ) ans += "&"; 
                else if (ent == "&gt;" ) ans += ">"; 
                else if (ent == "&lt;" ) ans += "<"; 
                else if (ent == "&frasl;" ) ans += "/"; 
                else ans += ent;
            }
        }
        return ans;
    }
};