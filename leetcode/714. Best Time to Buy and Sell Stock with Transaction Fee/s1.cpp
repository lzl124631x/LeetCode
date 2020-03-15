// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxProfit(vector<int>& A, int fee) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN;
        vector<int> dp(N + 1);
        for (int i = 0; i < N; ++i) {
            buy = max(buy, dp[i] - A[i]);
            dp[i + 1] = max(dp[i], A[i] - fee + buy);
        }
        return dp[N];
    }
};