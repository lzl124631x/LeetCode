// https://discuss.leetcode.com/topic/66709/c-easy-understood-solution-sort
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int cnt = 0, arrow = INT_MIN;
        for (auto p : points) {
            if (arrow != INT_MIN && p.first <= arrow) continue;
            arrow = p.second;
            ++cnt;
        }
        return cnt;
    }
};