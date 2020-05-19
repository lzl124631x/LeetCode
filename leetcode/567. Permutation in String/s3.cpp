// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/lzl124631x
// Time: O(S2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int M = s1.size(), N = s2.size(), i = 0, j = 0, goal[26] = {0}, cnt[26] = {0};
        for (char c : s1) goal[c - 'a']++;
        for (; j < N; ++i, ++j) {
            while (j < N && cnt[s2[j] - 'a'] + 1 <= goal[s2[j] - 'a']) cnt[s2[j++] - 'a']++;
            if (j - i == M) return true;
            while (j < N && i < j && s2[i] != s2[j]) cnt[s2[i++] - 'a']--;
        }
        return false;
    }
};