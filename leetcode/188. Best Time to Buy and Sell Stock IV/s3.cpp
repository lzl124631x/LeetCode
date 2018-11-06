// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/26169/clean-java-dp-solution-with-comment
class Solution {
private:
  int quickSolve(vector<int> &prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
    }
    return ans;
  }
public:
  int maxProfit(int k, vector<int>& prices) {
    if (k <= 0) return 0;
    if (k >= prices.size() / 2) return quickSolve(prices);
    int N = prices.size();
    vector<int> dp(N, 0);
    for (int i = 1; i <= k; ++i) {
      int localMax = INT_MIN;
      for (int j = 0; j < N; ++j) {
        localMax = max(localMax, dp[j] - prices[j]);
        dp[j] = max(dp[j - 1], prices[j] + localMax);
      }
    }
    return dp[N - 1];
  }
};