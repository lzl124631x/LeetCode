// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/24739/c-code-in-9-lines
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = -1;
        vector<int> m(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] > start) start = m[s[i]];
            m[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};