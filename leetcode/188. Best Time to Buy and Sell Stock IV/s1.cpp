// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(K)
// Ref: https://discuss.leetcode.com/topic/8984/a-concise-dp-solution-in-java
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (k >= prices.size() / 2) {
      int ans = 0;
      for (int i = 1; i < prices.size(); ++i) {
        ans += max(prices[i] - prices[i - 1], 0);
      }
      return ans;
    }
    vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
    for (int p : prices) {
      for (int i = 0; i < k; ++i) {
        buy[i + 1] = max(buy[i + 1], sell[i] - p);
        sell[i + 1] = max(sell[i + 1], buy[i + 1] + p);
      }
    }
    return sell[k];
  }
};

/*
Why is it `k >= N / 2` not `k >= N - 1`?
For prices of length N, we can do `N - 1` transactions at most indeed.
For example, for `[1,2,3]` we can do at most 2 transactions.
But actually doing 1 transaction is enough for this case.
Think about the fact that we never buy back what we sold on the same day,
so the maximum number of transactions should always be no more than `N / 2`.
*/