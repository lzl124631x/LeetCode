// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == s[N - j]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[N][N];
    }
};