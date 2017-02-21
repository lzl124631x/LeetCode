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