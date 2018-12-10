// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^5)
// Space: O(N^5)
class Solution {
private:
    unordered_map<string, bool> m;
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        if (s1 > s2) swap(s1, s2);
        string key = s1 + "#" + s2;
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        for (int i = 1; i < s1.size(); ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, i), r2 = s2.substr(i);
            string r2r = s2.substr(0, s1.size() - i), l2r = s2.substr(s1.size() - i);
            if ((isScramble(l1, l2) && isScramble(r1, r2))
               || (isScramble(l1, l2r) && isScramble(r1, r2r))) {
                ans = true;
                break;
            }
        }
        return m[key] = ans;
    }
};