class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        for (int i = 5; i <= n; ++i) {
            dp[i] = 3 * max(i - 3, dp[i - 3]);
        }
        return dp[n];
    }
};