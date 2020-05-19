// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(S2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int cnt[26] = {}, count = s1.size(), N = s1.size();
        for (char c : s1) cnt[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i) {
            if (i >= N) count += cnt[s2[i - N] - 'a']++ >= 0;
            count -= cnt[s2[i] - 'a']-- > 0;
            if (!count) return true;
        }
        return false;
    }
};