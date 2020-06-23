// OJ: https://leetcode.com/problems/online-stock-span/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(N)
class StockSpanner {
    vector<int> val = {INT_MAX}, prev = {-1};
public:
    StockSpanner() {}
    
    int next(int price) {
        int i = val.size() - 1;
        while (val[i] <= price) i = prev[i];
        val.push_back(price);
        prev.push_back(i);
        return val.size() - i - 1;
    }
};