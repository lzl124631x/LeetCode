// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(N^2 + NM)
class Solution {
    typedef long long LL;
public:
    int splitArray(vector<int>& A, int M) {
        int N = A.size();
        vector<vector<LL>> sum(N, vector<LL>(N, 0)), dp(M + 1, vector<LL>(N, INT_MAX));
        for (int i = 0; i < N; ++i) {
            LL s = 0;
            for (int j = i; j < N; ++j) {
                sum[i][j] = (s += A[j]);
            }
        }
        for (int i = 0; i < N; ++i) dp[1][i] = sum[0][i];
        for (int m = 2; m <= M; ++m) {
            for (int i = m - 1; i < N; ++i) {
                for (int j = m - 1; j <= i; ++j) {
                    dp[m][i] = min(dp[m][i], max(dp[m - 1][j - 1], sum[j][i]));
                }
            }
        }
        return dp[M][N - 1];
    }
};