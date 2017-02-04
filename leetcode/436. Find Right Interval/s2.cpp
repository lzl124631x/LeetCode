// https://discuss.leetcode.com/topic/65602/c-map-solution
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> m;
        int N = intervals.size();
        for (int i = 0; i < N; ++i) m[intervals[i].start] = i;
        vector<int> ans;
        for (auto it : intervals) {
            auto i = m.lower_bound(it.end);
            ans.push_back(i == m.end() ? -1 : i->second);
        }
        return ans;
    }
};