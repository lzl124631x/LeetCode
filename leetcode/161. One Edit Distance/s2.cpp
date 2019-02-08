// OJ: https://leetcode.com/problems/one-edit-distance/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) swap(s, t);
        if (s.size() - t.size() > 1) return false;
        int i = 0;
        while (i < t.size() && s[i] == t[i]) ++i;
        return s.size() > t.size() ? !s.compare(i + 1, string::npos, t, i)
                : (i != t.size() && !s.compare(i + 1, string::npos, t, i + 1));
    }
};