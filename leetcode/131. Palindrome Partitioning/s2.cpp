// OJ: https://leetcode.com/problems/palindrome-partitioning
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N^2)
// Ref: https://discuss.leetcode.com/topic/37756/java-dp-dfs-solution
class Solution {
private:
  vector<vector<bool>> dp;
  vector<vector<string>> ans;
  vector<string> tmp;
  void dfs(string &s, int start) {
    if (start == s.size()) { ans.push_back(tmp); return; }
    for (int i = start; i < s.size(); ++i) {
      if (dp[start][i]) {
        tmp.push_back(s.substr(start, i - start + 1));
        dfs(s, i + 1);
        tmp.pop_back();
      }
    }
  }
public:
  vector<vector<string>> partition(string s) {
    dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        if (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1])) dp[j][i] = true;
      }
    }
    dfs(s, 0);
    return ans;
  }
};