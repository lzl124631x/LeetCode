/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp (pair<Interval, int> a, pair<Interval, int> b) {
    return a.first.start < b.first.start;
}
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<pair<Interval, int>> v;
        int N = intervals.size();
        for (int i = 0; i < N; ++i) v.push_back(make_pair(intervals[i], i));
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for (auto it : intervals) {
            int end = it.end;
            int L = 0, R = N - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (v[M].first.start >= end) R = M - 1;
                else L = M + 1;
            }
            ans.push_back(L >= 0 && L < N ? v[L].second : -1);
        }
        return ans;
    }
};