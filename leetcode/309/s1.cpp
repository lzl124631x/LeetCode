// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN;
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            buy = max(buy, (i >= 1 ? dp[i - 1] : 0) - A[i]);
            dp[i + 1] = max(dp[i], buy + A[i]);
        }
        return dp[N];
    }
};