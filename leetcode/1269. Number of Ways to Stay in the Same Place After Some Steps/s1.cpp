// OJ: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
// Author: github.com/lzl124631x
// Time: O(SL)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    int numWays(int steps, int arrLen) {
        LL dp[2][251] = {0}, diff[3] = {-1, 0, 1}, mod = 1e9+7;
        dp[0][0] = 1;
        arrLen = min(251, arrLen);
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < arrLen; ++j) dp[i % 2][j] = 0;
            for (int j = 0; j < arrLen; ++j) {
                for (int d : diff) {
                    int t = j + d;
                    if (t < 0 || t >= arrLen) continue;
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][t]) % mod;
                }
            }
        }
        return dp[steps % 2][0];
    }
};