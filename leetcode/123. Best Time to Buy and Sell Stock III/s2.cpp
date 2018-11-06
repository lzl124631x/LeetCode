// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/5934/is-it-best-solution-with-o-n-o-1
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    for (int p : prices) {
      buy1 = max(buy1, -p);
      sell1 = max(sell1, buy1 + p);
      buy2 = max(buy2, sell1 - p);
      sell2 = max(sell2, buy2 + p);
    }
    return sell2;
  }
};