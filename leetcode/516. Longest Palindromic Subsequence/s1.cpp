// OJ: https://leetcode.com/problems/longest-palindromic-subsequence
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    if (s.empty()) return 0;
    vector<vector<int>> m(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); ++i) m[i][i] = 1;
    for (int len = 2; len <= s.size(); ++len) {
      for (int i = 0; i <= s.size() - len; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j]) m[i][j] = max(2 + m[i + 1][j - 1], max(m[i + 1][j], m[i][j - 1]));
        else m[i][j] = max(m[i + 1][j], m[i][j - 1]);
      }
    }
    return m[0][s.size() - 1];
  }
};