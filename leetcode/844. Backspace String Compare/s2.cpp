// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    void back(string &s, int &i) {
        if (i < 0 || s[i] != '#') return;
        int cnt = 0;
        while (i >= 0 && (s[i] == '#' || cnt)) {
            while (i >= 0 && s[i] == '#') ++cnt, --i;
            while (i >= 0 && s[i] != '#' && cnt) --cnt, --i;
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size(), j = t.size();
        while (i >= 0 && j >= 0) {
            back(s, i);
            back(t, j);
            if (i >= 0 && j >= 0) {
                if (s[i] == t[j]) --i, --j;
                else return false;
            }
        }
        back(s, i);
        back(t, j);
        return i < 0 && j < 0;
    }
};