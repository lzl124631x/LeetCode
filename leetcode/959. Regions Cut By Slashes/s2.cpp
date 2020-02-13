// OJ: https://leetcode.com/problems/regions-cut-by-slashes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    const int dirs[4][2] = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};
    int N;
    void dfs(vector<vector<int>> &g, int x, int y, int color) {
        if (x < 0 || x >= N || y < 0 || y >= N || g[x][y]) return;
        g[x][y] = color;
        for (auto &dir : dirs) dfs(g, x + dir[0], y + dir[1], color);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size();
        vector<vector<int>> g(3 * N, vector<int>(3 * N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '/') g[3 * i][3 * j + 2] = g[3 * i + 1][3 * j + 1] = g[3 * i + 2][3 * j] = 1;
                else if (grid[i][j] == '\\') g[3 * i][3 * j] = g[3 * i + 1][3 * j + 1] = g[3 * i + 2][3 * j + 2] = 1;
            }
        }
        N *= 3;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                 if (!g[i][j]) dfs(g, i, j, ++ans + 1);
            }
        }
        return ans;
    }
};