// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(min(N, K + W))
// Space: O(min(N, K + W))
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (!K || N >= K + W - 1) return 1;
        vector<double> dp(N + 1);
        dp[0] = 1;
        double ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (i > 1) dp[i] += dp[i - 1];
            if (i <= K) dp[i] += dp[i - 1] / W;
            if (i > W) dp[i] -= dp[i - W - 1]/W;
            if (i >= K) ans += dp[i];
        }
        return ans;
    }
};