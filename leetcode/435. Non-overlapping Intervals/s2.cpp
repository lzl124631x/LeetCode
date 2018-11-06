// OJ: https://leetcode.com/problems/non-overlapping-intervals
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
      [](Interval &a, Interval &b) { return a.end == b.end ? a.start < b.start : a.end < b.end; });
    int end = INT_MIN, cnt = 0;
    for (auto i : intervals) {
      if (i.start < end) ++cnt;
      else end = i.end;
    }
    return cnt;
  }
};