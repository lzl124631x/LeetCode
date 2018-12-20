// OJ: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.size() > s2.size()) swap(s1, s2);
        int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) dp[0][i] = dp[0][i - 1] + s2[i - 1];
        for (int i = 1; i <= M; ++i) {
            dp[i % 2][0] = dp[(i - 1) % 2][0] + s1[i - 1];
            for (int j = 1; j <= N; ++j) {
                if (s1[i - 1] == s2[j - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else dp[i % 2][j] = min(s1[i - 1] + dp[(i - 1) % 2][j], s2[j - 1] + dp[i % 2][j - 1]);
            }
        }
        return dp[M % 2][N];
    }
};