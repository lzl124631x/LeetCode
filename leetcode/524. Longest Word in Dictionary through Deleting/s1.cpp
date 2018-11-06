// OJ: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
// Author: github.com/lzl124631x
// Time: O(SD), where S is length of string s, D is the sum of lengths of strings in d.
// Space: O(1)
class Solution {
private:
  bool isSubstring(string &str, string &sub) {
    int i = 0;
    for (int j = 0; i < sub.size() && j < str.size(); ++j) {
      if (sub[i] == str[j]) ++i;
    }
    return i == sub.size();
  }
public:
  string findLongestWord(string s, vector<string>& d) {
    string ans;
    for (string word : d) {
      if (word.size() >= ans.size() && isSubstring(s, word) && (ans.size() < word.size() || word < ans)) ans = word;
    }
    return ans;
  }
};