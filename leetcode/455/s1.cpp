// OJ: https://leetcode.com/problems/assign-cookies
// Author: github.com/lzl124631x
// Time: O(max(GlogG, SlogS))
// Space: O(1)
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());
    auto ig = g.begin(), is = s.begin();
    int cnt = 0;
    while (ig != g.end() && is != s.end()) {
      if (*is >= *ig) {
        ++is;
        ++cnt;
      }
      ++ig;
    }
    return cnt;
  }
};