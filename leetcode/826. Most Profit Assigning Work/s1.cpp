// OJ: https://leetcode.com/problems/most-profit-assigning-work/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int, greater<int>> diffToProfit;
        int N = difficulty.size(), maxProfit = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            diffToProfit[difficulty[i]] = max(diffToProfit[difficulty[i]], profit[i]);
        }
        for (auto it = diffToProfit.rbegin(); it != diffToProfit.rend(); ++it) {
            it->second = maxProfit = max(maxProfit, it->second);
        }
        for (int w : worker) {
            auto it = diffToProfit.lower_bound(w);
            if (it != diffToProfit.end()) ans += it->second;
        }
        return ans;
    }
};