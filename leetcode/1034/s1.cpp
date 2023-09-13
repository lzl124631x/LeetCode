// OJ: https://leetcode.com/problems/coloring-a-border/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(vector<vector<int>> &G, int x, int y, int color) {
        if (x < 0 || x >= G.size() || y < 0 || y >= G[0].size() || G[x][y] != color) return;
        bool border = false;
        for (auto &dir : dirs) {
            int a = x + dir[0], b = y + dir[1];
            if (a < 0 || a >= G.size() || b < 0 || b >= G[0].size() || (G[a][b] > 0 && G[a][b] != color)) {
                border = true;
                break;
            }
        }
        G[x][y] = -color - (border ? 1 : 0);
        for (auto &dir : dirs) dfs(G, x + dir[0], y + dir[1], color);
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& G, int r0, int c0, int color) {
        int c = G[r0][c0];
        dfs(G, r0, c0, c);
        for (int i = 0; i < G.size(); ++i) {
            for (int j = 0; j < G[0].size(); ++j) {
                if (G[i][j] < 0) G[i][j] = G[i][j] == -c ? c : color;
            }
        }
        return G;
    }
};