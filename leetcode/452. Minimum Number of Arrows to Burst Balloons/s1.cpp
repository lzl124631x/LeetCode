// OJ: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end());
    int cnt = 0;
    for (auto it = points.begin(); it != points.end(); ++cnt) {
      int start = INT_MIN, end = INT_MAX;
      for (; it != points.end() && it->first <= end && it->second >= start; ++it) {
        start = max(start, it->first);
        end = min(end, it->second);
      }
    }
    return cnt;
  }
};