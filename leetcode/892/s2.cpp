// OJ: https://leetcode.com/problems/surface-area-of-3d-shapes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
private:
    int dirs[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size(), area = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!grid[i][j]) continue;
                area += 2;
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    int h = x < 0 || x >= N || y < 0 || y >= N ? 0 : grid[x][y];
                    area += max(grid[i][j] - h, 0);
                }
            }
        }
        return area;
    }
};