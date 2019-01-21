// OJ: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
  void reverseWords(string &s) {
    stringstream ss(s);
    string word, ans;
    while (ss >> word) {
      if (ans.size()) word += ' ';
      ans = word + ans;
    }
    s = ans;
  }
};