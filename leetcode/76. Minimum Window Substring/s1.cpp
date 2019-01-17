// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0, i = 0, j = 0, S = s.size(), T = t.size();
        int minLen = INT_MAX, begin = -1;
        unordered_map<char, int> m, seen;
        for (char c : t) m[c]++;
        while (j < S) {
            for (; j < S && cnt != T; ++j) {
                if (m.find(s[j]) == m.end()) continue;
                if (++seen[s[j]] <= m[s[j]]) ++cnt;
            }
            for (; cnt == T; ++i) {
                if (m.find(s[i]) == m.end()) continue;
                if (j - i < minLen) {
                    minLen = j - i;
                    begin = i;
                }
                if (--seen[s[i]] < m[s[i]]) --cnt;
            }
        }
        return begin == -1 ? "" : s.substr(begin, minLen);
    }
};