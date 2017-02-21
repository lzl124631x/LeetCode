// https://discuss.leetcode.com/topic/8984/a-concise-dp-solution-in-java
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