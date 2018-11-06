// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (s[i] == s[N - 1 - j]) dp[i + 1][j + 1] = dp[i][j] + 1;
        else dp[i + 1][j + 1] = maax(dp[i][j + 1], dp[i + 1][j]);
      }
    }
    return dp[N][N];
  }
};