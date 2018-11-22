// OJ: https://leetcode.com/problems/surface-area-of-3d-shapes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size(), area = 0;
        for (int i = 0; i < N; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) area += 2;
                area += abs(grid[i][j] - prev);
                prev = grid[i][j];
            }
            area += prev;
        }
        for (int i = 0; i < N; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                area += abs(grid[j][i] - prev);
                prev = grid[j][i];
            }
            area += prev;
        }
        return area;
    }
};