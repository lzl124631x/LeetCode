// OJ: https://leetcode.com/problems/palindrome-partitioning
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N * 2^N)
// Ref: https://discuss.leetcode.com/topic/2884/my-java-dp-only-solution-without-recursion-o-n-2
// Note: Slow, but worth a glance.
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    vector<vector<vector<string>>> answers(s.size() + 1);
    answers[0] = vector<vector<string>>(1, vector<string>());
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        if (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1])) {
          dp[j][i] = true;
          for (auto arr : answers[j]) {
            arr.push_back(s.substr(j, i - j + 1));
            answers[i + 1].push_back(arr);
          }
        }
      }
    }
    return answers[s.size()];
  }
};