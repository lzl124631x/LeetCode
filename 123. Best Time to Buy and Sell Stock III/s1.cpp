class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, N = prices.size();
        vector<int> m(N + 1, 0), n(N + 1, 0);
        int minVal = INT_MAX;
        for (int i = 0; i < N; ++i) {
            minVal = min(minVal, prices[i]);
            m[i] = max(m[i - 1], prices[i] - minVal);
        }
        int maxVal = INT_MIN;
        for (int i = N - 1; i >= 0; --i) {
            maxVal = max(maxVal, prices[i]);
            n[i] = max(n[i + 1], maxVal - prices[i]);
        }
        for (int i = 0; i <= N; ++i) {
            ans = max(ans, m[i] + n[i]);
        }
        return ans;
    }
};