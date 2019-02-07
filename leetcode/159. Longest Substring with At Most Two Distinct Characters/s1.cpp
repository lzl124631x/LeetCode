// OJ: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> cnt;
        while (j < s.size()) {
            while (j < s.size()) {
                cnt[s[j++]]++;
                if (cnt.size() > 2) break;
                ans = max(ans, j - i);
            }
            while (i < j && cnt.size() > 2) {
                char c = s[i++];
                cnt[c]--;
                if (!cnt[c]) cnt.erase(c);
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};