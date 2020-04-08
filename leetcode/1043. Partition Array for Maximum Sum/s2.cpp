// OJ: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        ++K;
        vector<int> dp(K);
        for (int i = 0; i < N; ++i) {
            int maxVal = 0;
            dp[i % K] = 0;
            for (int j = i, k = 0; j >= 0 && k < K - 1; --j, ++k) {
                maxVal = max(maxVal, A[j]);
                dp[i % K] = max(dp[i % K], (j == 0 ? 0 : dp[(j - 1) % K]) + maxVal * (i - j + 1));
            }
        }
        return dp[(N - 1) % K];
    }
};