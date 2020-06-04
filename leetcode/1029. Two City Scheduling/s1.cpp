// OJ: https://leetcode.com/problems/two-city-scheduling/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(N / 2 + 1));
        for (int i = 0; i < N; ++i) {
            dp[i + 1][0] = dp[i][0] + A[i][1];
            for (int j = 1; j <= min(i + 1, N / 2); ++j) {
                dp[i + 1][j] = min((i + 1 > j ? dp[i][j] + A[i][1] : INT_MAX), dp[i][j - 1] + A[i][0]);
            }
        }
        return dp[N][N / 2];
    }
};