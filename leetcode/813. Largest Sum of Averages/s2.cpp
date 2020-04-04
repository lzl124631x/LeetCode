// OJ: https://leetcode.com/problems/largest-sum-of-averages/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(NK)
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<vector<double>> dp(K + 1, vector<double>(N));
        double sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            dp[1][i] = sum / (i + 1);
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = k - 1; i < N; ++i) {
                double sum = 0;
                for (int j = i; j >= k - 1; --j) {
                    sum += A[j];
                    dp[k][i] = max(dp[k][i], dp[k - 1][j - 1] + sum / (i - j + 1));
                }
            }
        }
        return dp[K][N - 1];
    }
};