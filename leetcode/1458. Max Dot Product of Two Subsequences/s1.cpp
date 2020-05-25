// OJ: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxDotProduct(vector<int>& s, vector<int>& t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MIN));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i + 1][j + 1] = max({ max(0, dp[i][j]) + s[i] * t[j], dp[i + 1][j], dp[i][j + 1] });
            }
        }
        return dp[M][N];
    }
};