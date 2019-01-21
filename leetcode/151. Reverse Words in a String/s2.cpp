// OJ: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
  void reverseWords(string &s) {
    string ret;
    int i, j;
    for (i = s.size() - 1; i >= 0;) {
      while (i >= 0 && s[i] == ' ') --i;
      if (i < 0) break;
      if (!ret.empty()) ret += ' ';
      j = i;
      while (j >= 0 && s[j] != ' ') --j;
      for (int k = j + 1; k <= i; ++k) ret += s[k];
      i = j;
    }
    s = ret;
  }
};