// OJ: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = min(dp[i][j], k + max(k == i ? 0 : dp[i][k - 1], k == j ? 0 : dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};