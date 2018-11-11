// OJ: https://leetcode.com/problems/distinct-subsequences
// Author: github.com/lzl124631x
// Time: O(ST)
// Space: O(T)
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(t.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = t.size(); j > 0; --j) {
                if (s[i] == t[j - 1]) dp[j] += dp[j - 1];
            }
        }
        return dp[t.size()];
    }
};