// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  string reverseWords(string s) {
    int begin = 0;
    while (begin < s.size() && isspace(s[begin])) ++begin;
    while (begin < s.size()) {
      int end = begin;
      while (end < s.size() && !isspace(s[end])) ++end;
      reverse(s.begin() + begin, s.begin() + end);
      begin = end;
      while (begin < s.size() && isspace(s[begin])) ++begin;
    }
    return s;
  }
};