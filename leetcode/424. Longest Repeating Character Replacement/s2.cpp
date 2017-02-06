// https://discuss.leetcode.com/topic/63456/7-lines-c
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, cnt[26] = {};
        while (j < s.size()) {
            cnt[s[j++] - 'A']++;
            if (j - i - *max_element(cnt, cnt + 26) > k)
                cnt[s[i++] - 'A']--;
        }
        return j - i;
    }
};