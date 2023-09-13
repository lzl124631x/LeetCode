// OJ: https://leetcode.com/problems/magic-squares-in-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
private:
    bool isMagic(vector<vector<int>>& grid, int x, int y) {
        if (grid[x + 1][y + 1] != 5) return false;
        int cnt[9] = {0};
        for (int i = 0; i < 3; ++i) {
            int xSum = 0, ySum = 0;
            for (int j = 0; j < 3; ++j) {
                int v = grid[x + i][y + j];
                if (v < 1 || v > 9 || cnt[v - 1]) return false;
                cnt[v - 1]++;
                xSum += v;
                ySum += grid[x + j][y + i];
            }
            if (xSum != 15 || ySum != 15) return false;
        }
        return (grid[x][y] + grid[x + 2][y + 2] == 10)
            && (grid[x][y + 2] + grid[x + 2][y] == 10);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), cnt = 0;
        for (int i = 0; i <= M - 3; ++i) {
            for (int j = 0; j <= N - 3; ++j) {
                if (isMagic(grid, i, j)) ++cnt;
            }
        }
        return cnt;
    }
};