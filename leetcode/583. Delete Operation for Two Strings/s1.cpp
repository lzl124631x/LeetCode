// OJ: https://leetcode.com/problems/delete-operation-for-two-strings
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
  int minDistance(string word1, string word2) {
    int M = word1.size(), N = word2.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
        else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
    return M + N - 2 * dp[M][N];
  }
};