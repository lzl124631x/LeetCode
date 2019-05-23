// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MN)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1], len = strs.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; ++i) {
            int cm = 0, cn = 0;
            for (char c : strs[i]) {
                if (c == '0') ++cm;
                else ++cn;
            }
            for (int im = m; im >= cm; --im) {
                for (int in = n; in >= cn; --in) {
                    dp[im][in] = max(dp[im][in], dp[im - cm][in - cn] + 1);
                }
            }
        }
        return dp[m][n];
    }
};