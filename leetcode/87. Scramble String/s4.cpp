// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^4)
class Solution {
private:
    bool areAnagram(string &s1, string &s2) {
        unordered_map<char, int> m;
        for (int i = 0; i < s1.size(); ++i) {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for (auto &p : m) {
            if (p.second) return false;
        }
        return true;
    }
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        if (!areAnagram(s1, s2)) return false;
        for (int len = 1; len < s1.size(); ++len) {
            if ((isScramble(s1.substr(0, len), s2.substr(0, len))
                && isScramble(s1.substr(len), s2.substr(len)))
               || (isScramble(s1.substr(0, len), s2.substr(s2.size() - len))
                    && isScramble(s1.substr(len), s2.substr(0, s2.size() - len))))
                return true;
        }
        return false;
    }
};