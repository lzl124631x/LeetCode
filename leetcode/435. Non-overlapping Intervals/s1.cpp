// https://discuss.leetcode.com/topic/65594/java-least-is-most
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp (Interval a, Interval b) {
    return a.end == b.end ? a.start < b.start : a.end < b.end;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0].end, cnt = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= end) {
                end = intervals[i].end;
                ++cnt;
            }
        }
        return intervals.size() - cnt;
    }
};