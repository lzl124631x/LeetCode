// OJ: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int distinctSubseqII(string S) {
        int N = S.size(), mod = pow(10, 9) + 7;
        vector<vector<long long>> dp(2, vector<long long>(N + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
            dp[1][i] = dp[0][i];
            for (int j = 1; j < i; ++j) {
                if (S[i - 1] == S[j - 1]) dp[1][i] = (dp[1][i] - dp[1][j] + mod) % mod;
            }
        }
        return (dp[0][N] + dp[1][N] - 1) % mod;
    }
};