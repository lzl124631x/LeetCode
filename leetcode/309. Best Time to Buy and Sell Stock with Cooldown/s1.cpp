class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int N = prices.size(), localMax = INT_MIN;
        vector<int> dp(N, 0);
        for (int i = 0; i < N; ++i) {
            dp[i] = max((i >= 1 ? dp[i - 1] : 0), prices[i] + localMax);
            localMax = max(localMax, (i >= 2 ? dp[i - 2] : 0) - prices[i]);
        }
        return dp[N - 1];
    }
};