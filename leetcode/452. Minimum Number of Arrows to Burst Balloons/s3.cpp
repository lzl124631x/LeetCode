// OJ: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/84569/c-5-line-o-n-time
class Solution {
public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end());
    int cnt = 0;
    for (int i = 0; i < points.size(); ++cnt) {
      int right = INT_MAX;
      while (i < points.size() && right >= points[i].first)
        right = min(right, points[i++].second);
    }
    return cnt;
  }
};