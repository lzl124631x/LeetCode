// OJ: https://leetcode.com/problems/minimum-cost-for-tickets/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int N = days.size();
        vector<int> dp(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = min({ dp[i + 1] + costs[0],
                          dp[lower_bound(begin(days) + i, end(days), days[i] + 7) - begin(days)] + costs[1],
                          dp[lower_bound(begin(days) + i, end(days), days[i] + 30) - begin(days)] + costs[2] });
        }
        return dp[0];
    }
};