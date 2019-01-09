// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        int best = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < s[best]) best = i;
            if (--cnt[s[i]] == 0) break;
        }
        string t = s.substr(best + 1);
        t.erase(remove(t.begin(), t.end(), s[best]), t.end());
        return s[best] + removeDuplicateLetters(t);
    }
};