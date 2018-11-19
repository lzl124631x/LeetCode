// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int normalize(string &S) {
        int length = 0;
        for (char c : S) {
            if (c == '#') {
                if (length) --length;
            } else S[length++] = c;
        }
        return length;
    }
public:
    bool backspaceCompare(string S, string T) {
        int s = normalize(S), t = normalize(T);
        if (s != t) return false;
        for (int i = 0; i < s; ++i) {
            if (S[i] != T[i]) return false;
        }
        return true;
    }
};