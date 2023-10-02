// OJ: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
// Author: github.com/lzl124631x
// Time: O(M^2 * NK)
// Space: O(MNK)
// Ref: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/discuss/586576/C%2B%2B-Bottom-Up-Dynamic-Programming-with-Explanation
class Solution {
    typedef long long LL;
    LL dp[51][101][51] = {};
public:
    int numOfArrays(int n, int m, int k) {
        int mod = 1e9+7;
        for (int i = 0; i <= m; ++i) dp[1][i][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int t = 1; t <= k; ++t) {
                    LL s = 0;
                    s = (s + j * dp[i - 1][j][t]) % mod;
                    for (int x = 1; x < j; ++x) s = (s + dp[i - 1][x][t - 1]) %mod;
                    dp[i][j][t] = (dp[i][j][t] + s) % mod;
                }
            }
        }
        LL ans = 0;
        for (int i = 1; i <= m; ++i) ans = (ans + dp[n][i][k]) % mod;
        return ans;
    }
};