// OJ: https://leetcode.com/problems/bomb-enemy/
// Author: github.com/lzl124631x
// Time: O(MN(M+N))
// Space: O(1)
class Solution {
private:
    int M, N;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int count(vector<vector<char>>& grid, int x, int y, int dir[2]) {
        int ans = 0;
        while (true) {
            x += dir[0];
            y += dir[1];
            if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y] == 'W') break;
            if (grid[x][y] == 'E') ++ans;
        }
        return ans;
    }
    int count(vector<vector<char>>& grid, int x, int y) {
        int ans = 0;
        for (auto &dir : dirs) ans += count(grid, x, y, dir);
        return ans;
    }
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        M = grid.size();
        N = grid[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != '0') continue;
                ans = max(ans, count(grid, i, j));
            }
        }
        return ans;
    }
};