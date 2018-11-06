// OJ: https://leetcode.com/problems/palindrome-partitioning
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
  vector<vector<string>> ans;
  vector<string> tmp;
  bool isPalindrome(string &s, int first, int last) {
    while (first < last && s[first] == s[last]) ++first, --last;
    return first >= last;
  }
  void dfs(string &s, int start) {
    if (start == s.size()) { ans.push_back(tmp); return; }
    for (int i = start; i < s.size(); ++i) {
      if (isPalindrome(s, start, i)) {
        tmp.push_back(s.substr(start, i - start + 1));
        dfs(s, i + 1);
        tmp.pop_back();
      }
    }
  }
public:
  vector<vector<string>> partition(string s) {
    dfs(s, 0);
    return ans;
  }
};