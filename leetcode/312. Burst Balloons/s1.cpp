// OJ: https://leetcode.com/problems/burst-balloons/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; ++i) dp[i][i] = (i - 1 < 0 ? 1 : A[i - 1]) * A[i] * (i + 1 >= N ? 1 : A[i + 1]);
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   (k - 1 < i ? 0 : dp[i][k - 1])
                                   + (i - 1 < 0 ? 1 : A[i - 1]) * A[k] * (j + 1 >= N ? 1 : A[j + 1])
                                   + (k + 1 > j ? 0 : dp[k + 1][j]));
                }
            }
        }
        return dp[0][N - 1];
    }
};