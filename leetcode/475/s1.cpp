// OJ: https://leetcode.com/problems/heaters
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int j = 0, ans = INT_MIN;
    for (int h : houses) {
      while (j < heaters.size() && heaters[j] < h) ++j;
      int d = INT_MAX;
      if (j - 1 >= 0) d = min(d, abs(heaters[j - 1] - h));
      if (j < heaters.size()) d = min(d, abs(heaters[j] - h));
      ans = max(ans, d);
    }
    return ans;
  }
};