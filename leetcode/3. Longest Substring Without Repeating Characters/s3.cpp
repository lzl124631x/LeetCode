// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, cnt = 0, ans = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 1) cnt++;
            while (cnt) {
                if (m[s[i++]]-- == 2) cnt--;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};