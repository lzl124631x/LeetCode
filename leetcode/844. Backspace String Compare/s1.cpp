// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    string normalize(string &s) {
        int len = 0;
        for (char c : s) {
            if (c == '#') len = max(len - 1, 0);
            else s[len++] = c;
        }
        s.resize(len);
        return s;
    }
public:
    bool backspaceCompare(string S, string T) {
        return normalize(S) == normalize(T);
    }
};