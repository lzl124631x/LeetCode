// OJ: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int solve(vector<vector<int>> &dp, int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j]) return dp[i][j];
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; ++k) dp[i][j] = min(dp[i][j], k + max(solve(dp, i, k - 1), solve(dp, k + 1, j)));
        return dp[i][j];
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        return solve(dp, 1, n);
    }
};