// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN;
        vector<int> dp(3);
        for (int i = 0; i < N; ++i) {
            buy = max(buy, (i - 1 >= 0 ? dp[(i - 1) % 3] : 0) - A[i]);
            dp[(i + 1) % 3] = max(dp[i % 3], buy + A[i]);
        }
        return dp[N % 3];
    }
};