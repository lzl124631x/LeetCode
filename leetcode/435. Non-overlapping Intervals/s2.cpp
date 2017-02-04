// https://discuss.leetcode.com/topic/65594/java-least-is-most/10
bool cmp (Interval a, Interval b) {
    return a.end == b.end ? a.start < b.start : a.end < b.end;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0].end, cnt = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < end) {
                ++cnt;
            } else end = intervals[i].end;
        }
        return cnt;
    }
};