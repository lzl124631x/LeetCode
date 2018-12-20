// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; ++i) dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int i = 1; i <= N; ++i) dp[0][i] = dp[0][i - 1] + s2[i - 1];
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(s1[i - 1] + dp[i - 1][j], s2[j - 1] + dp[i][j - 1]);
            }
        }
        return dp[M][N];
    }
};