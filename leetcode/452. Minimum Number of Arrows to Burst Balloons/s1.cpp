class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        set<pair<int, int>> s(points.begin(), points.end());
        int cnt = 0;
        for (auto it = s.begin(); it != s.end(); ) {
            ++cnt;
            int start = INT_MIN, end = INT_MAX;
            while (it != s.end() && it->first <= end && it->second >= start) {
                start = max(start, it->first);
                end = min(end, it->second);
                ++it;
            }
        }
        return cnt;
    }
};