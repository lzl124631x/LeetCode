// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    vector<int> v1(N + 1, 0), v2(N + 1, 0);
    int minVal = INT_MAX, maxVal = INT_MIN, ans = 0;
    for (int i = 0, j = N - 1; i < N; ++i, --j) {
      minVal = min(minVal, prices[i]);
      maxVal = max(maxVal, prices[j]);
      v1[i + 1] = max(v1[i], prices[i] - minVal);
      v2[j] = max(v2[j + 1], maxVal - prices[j]);
    }
    for (int i = 0; i < N; ++i) ans = max(ans, v1[i] + v2[i]);
    return ans;
  }
};