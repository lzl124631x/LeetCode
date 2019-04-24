// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(A^2 * C)
// Space: O(AC)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1));
        for (int i = 0; i <= coins.size(); ++i) dp[0][i] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= coins.size(); ++j) {
                for (int k = 0; i - coins[j - 1] * k >= 0; ++k) {
                    dp[i][j] += dp[i - coins[j - 1] * k][j - 1];
                }
            }
        }
        return dp[amount][coins.size()];
    }
};