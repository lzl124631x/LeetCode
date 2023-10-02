// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MN)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int S = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < S; ++i) {
            int zero = count(strs[i].begin(), strs[i].end(), '0'), one = strs[i].size() - zero;
            for (int j = m; j >= 0; --j) {
                for (int k = n; k >= 0; --k) {
                    dp[j][k] = max(dp[j][k], j >= zero && k >= one ? 1 + dp[j - zero][k - one] : 0);
                }
            }
        }
        return dp[m][n];
    }
};