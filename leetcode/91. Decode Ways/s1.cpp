class Solution {
public:
  int numDecodings(string s) {
    if (s.empty()) return 0;
    int pre2 = 1, pre1 = 1, cur = 0;
    for (int i = 0; i < s.size() && pre1; ++i) {
      if (s[i] != '0') cur += pre1;
      if (i != 0 && s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
        cur += pre2;
      pre2 = pre1;
      pre1 = cur;
      cur = 0;
    }
    return pre1;
  }
};