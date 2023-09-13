// OJ: https://leetcode.com/problems/largest-sum-of-averages/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N)
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<double> dp(N);
        double sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            dp[i] = sum / (i + 1);
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = N - 1; i >= k - 1; --i) {
                double sum = 0;
                dp[i] = 0;
                for (int j = i; j >= k - 1; --j) {
                    sum += A[j];
                    dp[i] = max(dp[i], dp[j - 1] + sum / (i - j + 1));
                }
            }
        }
        return dp[N - 1];
    }
};