// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(AC)
// Space: O(A)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int j = 1; j <= coins.size(); ++j) {
            for (int i = 1; i <= amount; ++i) {
                if (i - coins[j - 1] >= 0) dp[i] += dp[i - coins[j - 1]];
            }
        }
        return dp[amount];
    }
};