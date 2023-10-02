// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(KW)
// Space: O(1)
// NOTE: This solution will get TLE
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (N >= K + W - 1) return 1;
        vector<double> dp(K + W);
        dp[0] = 1;
        for (int i = 0; i < K; ++i) {
            for (int j = 1; j <= W && i + j <= N; ++j) dp[i + j] += dp[i] / W;
        }
        return accumulate(begin(dp) + K, begin(dp) + N + 1, 0.0);
    }
};