// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(K)
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
        vector<int> sell(K + 1), buy(K + 1, INT_MIN);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k <= K; ++k) {
                buy[k] = max(buy[k], sell[k - 1] - A[i]);
                sell[k] = max(sell[k], A[i] + buy[k]);
            }
        }
        return sell[K];
    }
};