// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
    int M, N;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int eraseIsland(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        int size = 1;
        for (auto &dir : dirs) {
            int i = x + dir[0], j = y + dir[1];
            if (i < 0 || i >= M || j < 0 || j >= N || !grid[i][j]) continue;
            size += eraseIsland(grid, i, j);
        }
        return size;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        M = grid.size();
        N = grid[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!grid[i][j]) continue;
                ans = max(ans, eraseIsland(grid, i, j));
            }
        }
        return ans;
    }
};