// OJ: https://leetcode.com/problems/count-servers-that-communicate/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M+N)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), ans = 0;
        vector<int> row(M, 0), col(N, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] && (row[i] > 1 || col[j] > 1)) ++ans;
            }
        }
        return ans;
    }
};