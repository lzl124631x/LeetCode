// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  string reverseWords(string s) {
    for (int i = 0, int begin = 0; i <= s.size(); ++i) {
      if (i == s.size() || isspace(s[i])) {
        reverse(s.begin() + begin, s.begin() + i);
        begin = i + 1;
      }
    }
    return s;
  }
};