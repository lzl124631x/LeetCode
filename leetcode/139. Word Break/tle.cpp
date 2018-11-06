// OJ: https://leetcode.com/problems/word-break
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(S)
class Solution {
private:
  unordered_set<string> dict;
  bool dfs(string &s, int start) {
    if (start == s.size()) return true;
    for (int i = start; i < s.size(); ++i) {
      string sub = s.substr(start, i - start + 1);
      if (!dict.count(sub)) continue;
      if (dfs(s, i + 1)) return true;
    }
    return false;
  }
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    for (auto word : wordDict) dict.insert(word);
      return dfs(s, 0);
  }
};