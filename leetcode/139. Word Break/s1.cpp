// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> ws(dict.begin(), dict.end());
        int N = s.size();
        vector<bool> dp(N + 1);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i - 1; j >= 0 && !dp[i]; --j) {
                if (!dp[j] || !ws.count(s.substr(j, i - j))) continue;
                dp[i] = true;
            }
        }
        return dp[N];
    }
};