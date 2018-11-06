// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size(), localMax = INT_MIN, ans = 0, prev1 = 0, prev2 = 0;
    for (int i = 0; i < N; ++i) {
      ans = max(prev1, prices[i] + localMax);
      localMax = max(localMax, prev2 - prices[i]);
      prev2 = prev1;
      prev1 = ans;
    }
    return ans;
  }
};