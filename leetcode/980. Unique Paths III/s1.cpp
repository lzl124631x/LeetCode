// OJ: https://leetcode.com/problems/unique-paths-iii/
// Author: github.com/lzl124631x
// Time: O(4^(MN))
// Space: O(MN)
class Solution {
private:
    int ans = 0, target = 0, visited = 0, M, N;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 2) {
            if (visited == target) ++ans;
            return;
        }
        ++visited;
        grid[x][y] = -1;
        for (auto dir : dirs) {
            int i = x + dir[0], j = y + dir[1];
            if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == -1) continue;
            dfs(grid, i, j);
        }
        grid[x][y] = 0;
        --visited;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int x, y;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    ++target;
                } else if (!grid[i][j]) ++target;
            }
        }
        dfs(grid, x, y);
        return ans;
    }
};