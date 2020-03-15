// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(KN)
class Solution {
public:
    int maxProfit(int K, vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        if (K >= N / 2) {
           int ans = 0;
            for (int i = 1; i < N; ++i) ans += max(0, A[i] - A[i - 1]);
            return ans;
        }
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for (int k = 1; k <= K; ++k) {
            int buy = INT_MIN;
            for (int i = 0; i < N; ++i) {
                buy = max(buy, dp[k - 1][i] - A[i]);
                dp[k][i + 1] = max(dp[k][i], A[i] + buy);
            }
        }
        return dp[K][N];
    }
};