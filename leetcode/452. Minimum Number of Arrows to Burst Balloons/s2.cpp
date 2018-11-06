// OJ: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/66709/c-easy-understood-solution-sort
class Solution {
public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end(),
        [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });
    int cnt = 0, right = INT_MIN;
    for (auto p : points) {
      if (right != INT_MIN && p.first <= right) continue;
      right = p.second;
      ++cnt;
    }
    return cnt;
  }
};