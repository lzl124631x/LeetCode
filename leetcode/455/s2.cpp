// OJ: https://leetcode.com/problems/assign-cookies
// Author: github.com/lzl124631x
// Time: O(max(GlogG, SlogS))
// Space: O(1)
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int i = g.size() - 1, j = s.size() - 1; i >= 0 && j >= 0; --i, --j) {
      while (i >= 0 && s[j] < g[i]) --i;
      if (i >= 0) ++cnt;
    }
    return cnt;
  }
};