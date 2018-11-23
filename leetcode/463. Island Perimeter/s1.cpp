// OJ: https://leetcode.com/problems/island-perimeter/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int M = grid.size(), N = grid[0].size();
        int peri = 0;
        for (int i = 0; i < M; ++i) {
            auto row = grid[i];
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) continue;
                if (i - 1 < 0 || grid[i - 1][j] == 0) ++peri;
                if (j - 1 < 0 || grid[i][j - 1] == 0) ++peri;
                if (i + 1 >= M || grid[i + 1][j] == 0) ++peri;
                if (j + 1 >= N || grid[i][j + 1] == 0) ++peri;
            }
        }
        return peri;
    }
};