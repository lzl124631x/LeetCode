// https://discuss.leetcode.com/topic/8984/a-concise-dp-solution-in-java
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
        vector<int> buy(k, INT_MIN), sell(k, 0);
        for (int p : prices) {
            for (int i = k - 1; i >= 0; --i) {
                sell[i] = max(sell[i], buy[i] + p);
                buy[i] = max(buy[i], (i >= 1 ? sell[i - 1] : 0) - p);
            }
        }
        return sell[k - 1];
    }
};
