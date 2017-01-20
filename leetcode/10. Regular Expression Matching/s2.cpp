class Solution {
private:
    inline bool matchChar(string &s, int i, string &p, int j) {
        return p[j] == '.' ? i < s.size() : s[i] == p[j];
    }
    bool isMatch(string s, int i, string p, int j) {
        if (j == p.size()) return i == s.size();
        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool ans = false;
            while (!(ans = isMatch(s, i, p, j + 2))
            && matchChar(s, i, p, j)) ++i;
            return ans;
        } else {
            return matchChar(s, i, p, j) && isMatch(s, i + 1, p, j + 1);
        }
    }
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};