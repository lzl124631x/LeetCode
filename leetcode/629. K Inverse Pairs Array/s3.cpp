// OJ: https://leetcode.com/problems/k-inverse-pairs-array/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int kInversePairs(int N, int K) {
        if (K > N * (N - 1) / 2) return 0;
        vector<vector<int>> dp(2, vector<int>(K + 1, 0));
        dp[0][0] = dp[1][0] = 1;
        int mod = 1e9 + 7;
        for (int n = 2; n <= N; ++n) {
            int bound = min(K, n * (n - 1) / 2);
            for (int k = 1; k <= bound; ++k) {
                dp[n % 2][k] = (dp[n % 2][k - 1] + (mod + dp[(n - 1) % 2][k] - dp[(n - 1) % 2][k - min(k, n - 1) - 1]) % mod) % mod;
            }
        }
        return dp[N % 2][K];
    }
};