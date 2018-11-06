// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int N = s.size();
    vector<vector<int>> dp(2, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (s[i] == s[N - 1 - j]) dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
        else dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
      }
    }
    return dp[N % 2][N];
  }
};