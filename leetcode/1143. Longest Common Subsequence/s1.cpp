// OJ: https://leetcode.com/problems/longest-common-subsequence/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[M][N];
    }
};