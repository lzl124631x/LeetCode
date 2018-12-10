// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^(N+1))
// Space: O(N^(N+1))
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        for (int i = 1; i < s1.size(); ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, i), r2 = s2.substr(i);
            string r2r = s2.substr(0, s1.size() - i), l2r = s2.substr(s1.size() - i);
            if ((isScramble(l1, l2) && isScramble(r1, r2))
               || (isScramble(l1, l2r) && isScramble(r1, r2r))) return true;
        }
        return false;
    }
};