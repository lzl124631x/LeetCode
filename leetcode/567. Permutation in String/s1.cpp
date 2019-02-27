// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(S2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int N = s1.size();
        int cnts[26] = {0};
        for (char c : s1) cnts[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i) {
            cnts[s2[i] - 'a']--;
            if (i - N >= 0) cnts[s2[i - N] - 'a']++;
            bool match = true;
            for (int j = 0; j < 26 && match; ++j) {
                if (cnts[j]) match = false;
            }
            if (match) return true;
        }
        return false;
    }
};