// OJ: https://leetcode.com/problems/heaters
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int h : houses) {
      int L = 0, R = heaters.size() - 1;
      while (L <= R) {
        int M = (L + R) / 2;
        if (heaters[M] >= h) R = M - 1;
        else L = M + 1;
      }
      int d = INT_MAX;
      if (L < heaters.size()) d = min(d, heaters[L] - h);
      if (R >= 0) d = min(d, h - heaters[R]);
      ans = max(ans, d);
    }
    return ans;
  }
};