// OJ: https://leetcode.com/problems/largest-sum-of-averages/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(NK + N^2)
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<vector<double>> avg(N + 1, vector<double>(N + 1));
        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int j = i; j < N; ++j) {
                sum += A[j];
                avg[i][j] = (double)sum / (j - i + 1);
            }
        }
        vector<vector<double>> dp(K + 1, vector<double>(N));
        for (int i = 0; i < N; ++i) dp[1][i] = avg[0][i];
        for (int k = 2; k <= K; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = k - 1; j <= i; ++j) {
                    dp[k][i] = max(dp[k][i], dp[k - 1][j - 1] + avg[j][i]);
                }
            }
        }
        return dp[K][N - 1];
    }
};