// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int minVal = INT_MAX, ans = 0;
    for (int p : prices) {
      minVal = min(minVal, p);
      ans = max(ans, p - minVal);
    }
    return ans;
  }
};