// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& A, int fee) {
        if (A.empty()) return 0;
        int N = A.size(), buy = INT_MIN, sell = 0;
        for (int i = 0; i < N; ++i) {
            buy = max(buy, sell - A[i]);
            sell = max(sell, A[i] - fee + buy);
        }
        return sell;
    }
};