// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(KN)
// Space: O(K)
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size();
        vector<int> dp(3);
        vector<int> maxVal(3, INT_MIN);
        for (int i = 0; i < N; ++i) {
            for (int k = 1; k < 3; ++k) {
                maxVal[k] = max(maxVal[k], dp[k - 1] - A[i]);
                dp[k] = max(dp[k], A[i] + maxVal[k]);
            }
        }
        return dp[2];
    }
};