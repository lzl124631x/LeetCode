// OJ: https://leetcode.com/problems/palindrome-partitioning-iii/
// Author: github.com/lzl124631x
// Time: O(K * N^2)
// Space: O(K * N^2)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int palindromePartition(string s, int K) {
        int N = s.size();
        vector<vector<vector<LL>>> dp(K + 1, vector<vector<LL>>(N, vector<LL>(N, 1e9)));
        for (int i = 0; i < N; ++i) dp[1][i][i] = 0;
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                dp[1][i][j] = (s[i] != s[j]) + (i + 1 <= j - 1 ? dp[1][i + 1][j - 1] : 0);
            }
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = N - 2; i >= 0; --i) {
                for (int j = i + k - 1; j < N; ++j) {
                    for (int t = i + k - 2; t < j; ++t) {
                        setMin(dp[k][i][j], dp[k - 1][i][t] + dp[1][t + 1][j]);
                    }
                }
            }
        }
        return dp[K][0][N - 1];
    }
};