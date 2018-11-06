// OJ: https://leetcode.com/problems/non-overlapping-intervals
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/65594/java-least-is-most
class Solution {
public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
      [](Interval &a, Interval &b) { return a.end == b.end ? a.start < b.start : a.end < b.end; });
    int end = INT_MIN, cnt = 0;
    for (auto i : intervals) {
      if (i.start >= end) {
        end = i.end;
        ++cnt;
      }
    }
    return intervals.size() - cnt;
  }
};