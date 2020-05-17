// OJ: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cnt[26] = {};
        vector<int> ans;
        int M = s.size(), N = p.size(), count = N;
        for (char c : p) ++cnt[c - 'a'];
        for (int i = 0; i < M; ++i) {
            if (i >= N && cnt[s[i - N] - 'a']++ >= 0) ++count;
            if (cnt[s[i] - 'a']-- > 0) --count;
            if (!count) ans.push_back(i - N + 1);
        }
        return ans;
    }
};