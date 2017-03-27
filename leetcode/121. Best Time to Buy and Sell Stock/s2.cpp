// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy = INT_MIN, sell = 0;
    for (int p : prices) {
      buy = max(buy, -p);
      sell = max(sell, buy + p);
    }
    return sell;
  }
};