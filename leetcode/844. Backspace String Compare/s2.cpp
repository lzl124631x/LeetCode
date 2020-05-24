// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    void back(string &s, int &i) {
        if (i < 0 || s[i] != '#') return;
        int cnt = 0;
        for (; i >= 0 && (cnt || s[i] == '#'); --i) {
            if (s[i] == '#') ++cnt;
            else --cnt;
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        while (i >= 0 || j >= 0) {
            back(S, i);
            back(T, j);
            if ((i >= 0 && j < 0) || (i < 0 && j >= 0)) return false;
            for (; i >= 0 && j >= 0 && S[i] != '#' && T[j] != '#'; --i, --j) {
                if (S[i] != T[j]) return false;
            } 
        }
        return true;
    }
};