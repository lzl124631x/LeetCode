// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(AC)
// Space: O(AC)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1));
        for (int i = 0; i <= coins.size(); ++i) dp[0][i] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= coins.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + (i - coins[j - 1] >= 0 ? dp[i - coins[j - 1]][j] : 0);
            }
        }
        return dp[amount][coins.size()];
    }
};