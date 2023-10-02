// OJ: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(max(M, N))
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), ans = 0;
        vector<int> maxHeightPerRow(M, 0), maxHeightPerCol(N, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                maxHeightPerRow[i] = max(maxHeightPerRow[i], grid[i][j]);
            }
        }
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) {
                maxHeightPerCol[j] = max(maxHeightPerCol[j], grid[i][j]);
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans += max(0, min(maxHeightPerRow[i], maxHeightPerCol[j]) - grid[i][j]);
            }
        }
        return ans;
    }
};