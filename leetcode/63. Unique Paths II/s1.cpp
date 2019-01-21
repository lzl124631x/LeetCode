// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<int> memo(N, 0);
        memo[N - 1] = 1;
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (obstacleGrid[i][j] == 1) memo[j] = 0;
                else memo[j] += j == N - 1 ? 0 : memo[j + 1];
            }
        }
        return memo[0];
    }
};