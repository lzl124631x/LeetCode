// OJ: https://leetcode.com/problems/projection-area-of-3d-shapes/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int N = grid.size(), i = 0; i < N; ++i) {
            int max1 = 0, max2 = 0;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) ++cnt;
                max1 = max(max1, grid[i][j]);
                max2 = max(max2, grid[j][i]);
            }
            cnt += max1 + max2;
        }
        return cnt;
    }
};