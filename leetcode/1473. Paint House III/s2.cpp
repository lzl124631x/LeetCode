// OJ: https://leetcode.com/problems/paint-house-iii/
// Author: github.com/lzl124631x
// Time: O(N^2 * MT)
// Space: O(MNT)
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int INF = 1e6;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 2, INF)));
        for (int last = 0; last <= n; ++last) dp[m][last][target] = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int last = 0; last <= n; ++last) {
                for (int cnt = 0; cnt <= target; ++cnt) {
                    if (houses[i]) dp[i][last][cnt] = dp[i + 1][houses[i]][houses[i] == last ? cnt : (cnt + 1)];
                    else {
                        for (int j = 1; j <= n; ++j) dp[i][last][cnt] = min(dp[i][last][cnt], dp[i + 1][j][j == last ? cnt : (cnt + 1)] + cost[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][0][0] == INF ? -1 : dp[0][0][0];
    }
};