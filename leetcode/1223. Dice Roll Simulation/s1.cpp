// OJ: https://leetcode.com/problems/dice-roll-simulation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/dice-roll-simulation/discuss/403756/Java-Share-my-DP-solution
class Solution {
public:
    int dieSimulator(int n, vector<int>& A) {
        long mod = 1e9+7;
        vector<vector<long>> dp(n, vector<long>(7));
        for (int i = 0; i < 6; ++i) dp[0][i] = 1;
        dp[0][6] = 6;
        for (int i = 1; i < n; ++i) {
            long sum = 0;
            for (int j = 0; j < 6; ++j) {
                dp[i][j] = dp[i - 1][6];
                if (i < A[j]) sum = (sum + dp[i][j]) % mod;
                else {
                    if (i - A[j] - 1 >= 0) dp[i][j] = (dp[i][j] - (dp[i - A[j] - 1][6] - dp[i - A[j] - 1][j]) + mod) % mod;
                    else dp[i][j] = (dp[i][j] - 1) % mod;
                    sum = (sum + dp[i][j]) % mod;
                }
            }
            dp[i][6] = sum;
        }
        return dp[n - 1][6];
    }
};