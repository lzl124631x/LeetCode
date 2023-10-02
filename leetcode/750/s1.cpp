// OJ: https://leetcode.com/problems/number-of-corner-rectangles/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(C^2) where C is the count of 1s.
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), ans = 0;
        map<int, set<int>> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!grid[i][j]) continue;
                m[i].insert(j);
            }
        }
        for (auto i = m.begin(); i != m.end(); ++i) {
            for (auto j = next(i); j != m.end(); ++j) {
                int cnt = 0;
                for (int y : i->second) {
                    if (j->second.find(y) == j->second.end()) continue;
                    ++cnt;
                }
                ans += cnt * (cnt - 1) / 2;
            }
        }
        return ans;
    }
};