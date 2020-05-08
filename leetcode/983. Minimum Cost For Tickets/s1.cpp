// OJ: https://leetcode.com/problems/minimum-cost-for-tickets/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<int> m;
    int dp(vector<int> &days, vector<int>& costs, int i) {
        int N = days.size();
        if (i == N) return 0;
        if (m[i] != INT_MAX) return m[i];
        int ans = dp(days, costs, i + 1) + costs[0], j = i;
        while (j < N && days[j] < days[i] + 7) ++j;
        ans = min(ans, dp(days, costs, j) + costs[1]);
        while (j < N && days[j] < days[i] + 30) ++j;
        ans = min(ans, dp(days, costs, j) + costs[2]);
        return m[i] = ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        m.assign(days.size(), INT_MAX);
        return dp(days, costs, 0);
    }
};