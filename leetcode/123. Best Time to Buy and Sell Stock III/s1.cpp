// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<vector<int>> dp(3, vector<int>(N + 1));
        for (int k = 1; k < 3; ++k) {
            int maxVal = INT_MIN;
            for (int i = 0; i < N; ++i) {
                maxVal = max(maxVal, dp[k - 1][i] - A[i]);
                dp[k][i + 1] = max(dp[k][i], A[i] + maxVal);
            }
        }
        return dp[2][N];
    }
};