// OJ: https://leetcode.com/problems/ransom-note/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for (char c : magazine) cnt[c - 'a']++;
        for (char c : ransomNote) {
            if (--cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};