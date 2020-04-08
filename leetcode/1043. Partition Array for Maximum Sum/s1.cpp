// OJ: https://leetcode.com/problems/partition-array-for-maximum-sum/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int maxVal = 0;
            for (int j = i, k = 0; j >= 0 && k < K; --j, ++k) {
                maxVal = max(maxVal, A[j]);
                dp[i] = max(dp[i], (j == 0 ? 0 : dp[j - 1]) + maxVal * (i - j + 1));
            }
        }
        return dp[N - 1];
    }
};