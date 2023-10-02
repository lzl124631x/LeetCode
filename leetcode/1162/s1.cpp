// OJ: https://leetcode.com/problems/as-far-from-land-as-possible/
// Author: github.com/lzl124631x
// Time: O(MNL) where grid is of size M*N and L is the count of lands.
// Space: O(L)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> lands;
        int M = grid.size(), N = grid[0].size(), ans = -1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) lands.emplace_back(i, j);
            }
        }
        if (lands.empty() || M * N == lands.size()) return -1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) continue;
                int dist = INT_MAX;
                for (auto &p : lands) {
                    int d = abs(p.first - i) + abs(p.second - j);
                    dist = min(dist, d);
                    if (dist <= ans) break;
                }
                ans = max(ans, dist);
            }
        }
        return ans;
    }
};