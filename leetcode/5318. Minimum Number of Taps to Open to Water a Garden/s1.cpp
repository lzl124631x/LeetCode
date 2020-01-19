// OJ: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> v;
        for (int i = 0; i < ranges.size(); ++i)
            v.emplace_back(max(0, i - ranges[i]),  min(n, i + ranges[i]));
        sort(v.begin(), v.end());
        int end = 0, newEnd = 0, ans = 0;
        for (int i = 0; i < v.size() && end != n; ++i) {
            if (v[i].first > end) return -1;
            newEnd = max(newEnd, v[i].second);
            if (i + 1 == v.size() || v[i + 1].first > end) {
                end = newEnd;
                ++ans;
            }
        }
        return ans;
    }
};