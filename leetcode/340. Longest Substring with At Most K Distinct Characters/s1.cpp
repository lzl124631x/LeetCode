// OJ: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> m(128, 0);
        int i = 0, j = 0, ans = 0, cnt = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 0) cnt++;
            while (cnt > k) {
                if (m[s[i++]]-- == 1) cnt--;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};