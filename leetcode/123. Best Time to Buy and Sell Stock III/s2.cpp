// https://discuss.leetcode.com/topic/5934/is-it-best-solution-with-o-n-o-1

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
        for (int p : prices) {
            sell2 = max(sell2, p + buy2);
            buy2 = max(buy2, sell1 - p);
            sell1 = max(sell1, p + buy1);
            buy1 = max(buy1, -p);
        }
        return sell2;
    }
};