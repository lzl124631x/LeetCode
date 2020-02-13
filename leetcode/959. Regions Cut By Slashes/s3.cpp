// OJ: https://leetcode.com/problems/regions-cut-by-slashes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
#define TO(d) dfs(grid, g, x + dirs[d][0], y + dirs[d][1], d, color)
class Solution {
    int N;
    void setLeftColor(vector<vector<int>> &g, int x, int y, int color) {
        g[x][y] += color * 100;
    }
    void setRightColor(vector<vector<int>> &g, int x, int y, int color) {
        g[x][y] += color;
    }
    int getLeftColor(vector<vector<int>> &g, int x, int y) {
        return g[x][y] / 100;
    }
    int getRightColor(vector<vector<int>> &g, int x, int y) {
        return g[x][y] % 100;
    }
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // 0 U, 1 R, 2 D, 3 L
    void dfs(vector<string>& grid, vector<vector<int>> &g, int x, int y, int d, int color) {
        if (x < 0 || x >= N || y < 0 || y >= N) return;
        if (grid[x][y] == ' ') {
            if (g[x][y]) return;
            g[x][y] = color;
            for (int i = 0; i < 4; ++i) TO(i);
        } else if (grid[x][y] == '/') {
            if (!getLeftColor(g, x, y) && (d == 2 || d == 1)) {
                setLeftColor(g, x, y, color);
                TO(0);
                TO(3);
            }
            if (!getRightColor(g, x, y) && (d == 0 || d == 3)) {
                setRightColor(g, x, y, color);
                TO(1);
                TO(2);
            }
        } else {
            if (!getLeftColor(g, x, y) && (d == 1 || d == 0)) {
               setLeftColor(g, x, y, color);
                TO(2);
                TO(3);
            }
            if (!getRightColor(g, x, y) && (d == 2 || d == 3)) {
                setRightColor(g, x, y, color);
                TO(0);
                TO(1);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        N = grid.size();
        int color = 0;
        vector<vector<int>> g(N, vector<int>(N, 0));
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (grid[x][y] == ' ') {
                    if (!g[x][y]) dfs(grid, g, x, y, 0, ++color);
                }
                else if (grid[x][y] == '/') {
                    if (!getLeftColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 1, color);
                        dfs(grid, g, x, y, 2, color);
                    }
                    if (!getRightColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 0, color);
                        dfs(grid, g, x, y, 3, color);
                    }
                } else {
                    if (!getLeftColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 0, color);
                        dfs(grid, g, x, y, 1, color);
                    }
                    if (!getRightColor(g, x, y)) {
                        ++color;
                        dfs(grid, g, x, y, 2, color);
                        dfs(grid, g, x, y, 3, color);
                    }
                }
            }
        }
        return color;
    }
};