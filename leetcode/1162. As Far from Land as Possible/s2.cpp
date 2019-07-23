// OJ: https://leetcode.com/problems/as-far-from-land-as-possible/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int M = grid.size(), N = grid[0].size(), ans = -1;
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) q.emplace(i, j);
            }
        }
        if (q.empty() || M * N == q.size()) return -1;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto p = q.front();
                q.pop();
                for (auto &dir : dirs) {
                    int x = p.first + dir[0], y = p.second + dir[1];
                    if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y]) continue;
                    q.emplace(x, y);
                    grid[x][y] = 1;
                }
            }
            ++ans;
        }
        return ans;
    }
};