// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MNS)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int S = strs.size();
        vector<vector<vector<int>>> dp(S + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 0; i < S; ++i) {
            int zero = count(strs[i].begin(), strs[i].end(), '0'), one = strs[i].size() - zero;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i + 1][j][k] = max(dp[i][j][k], j >= zero && k >= one ? 1 + dp[i][j - zero][k - one] : 0);
                }
            }
        }
        return dp[S][m][n];
    }
};