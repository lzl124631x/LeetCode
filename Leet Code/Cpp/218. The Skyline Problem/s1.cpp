// https://discuss.leetcode.com/topic/14939/my-c-code-using-one-priority-queue-812-ms
bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
         vector<pair<int, int>> ans;
         sort(buildings.begin(), buildings.end(), cmp);
         int i = 0, x = 0, y = 0, N = buildings.size();
         priority_queue<pair<int, int>> live;// first: height, second: right
         while (i < N || !live.empty()) {
             if (i < N && (live.empty() || live.top().second >= buildings[i][0])) {
                 x = buildings[i][0];
                 while (i < N && buildings[i][0] == x) {
                     live.push(make_pair(buildings[i][2], buildings[i][1]));
                     ++i;
                 }
             } else {
                 x = live.top().second;
                 while (!live.empty() && live.top().second <= x) live.pop();
             }
             y = live.empty() ? 0 : live.top().first;
             if (ans.empty() || ans.back().second != y) ans.push_back(make_pair(x, y));
         }
         return ans;
    }
};