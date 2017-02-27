class Solution {
public:
  string shortestPalindrome(string s) {
    if (s.empty()) return s;
    int N = s.size();
    vector<vector<int>> dp{ vector<int>(N, 0), vector<int>(N, 1) };
    for (int len = 2; len <= N; ++len) {
      for (int i = 0; i <= N - len; ++i) {
        if (s[i] == s[i + len - 1] && (len == 2 || dp[len % 2][i + 1] == len - 2)) {
          dp[len % 2][i] = len;
        }
      }
    }
    string prefix(s.rbegin(), s.rbegin() + N - max(dp[0][0], dp[1][0]));
    return prefix + s;
  }
};