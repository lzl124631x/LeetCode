// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(K + W)
// Space: O(K + W)
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (!K || N >= K + W - 1) return 1;
        vector<double> dp(K + W);
        for (int i = K; i < K + W && i <= N; ++i) dp[i] = 1;
        double sum = min(N - K + 1, W);
        for (int i = K - 1; i >= 0; --i) {
            dp[i] = sum / W;
            sum += dp[i] - dp[i + W];
        }
        return dp[0];
    }
}