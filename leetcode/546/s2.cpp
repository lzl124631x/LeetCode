// OJ: https://leetcode.com/problems/remove-boxes/
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^3)
// Ref: https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
class Solution {
public:
    int removeBoxes(vector<int>& A) {
        int N = A.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N)));
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k <= i; ++k) dp[i][i][k] = (k + 1) * (k + 1);
        }
        for (int len = 1; len < N; ++len) {
            for (int j = len; j < N; ++j) {
                int i = j - len;
                for (int k = 0; k <= i; ++k) {
                    int ans = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for (int m = i + 1; m <= j; ++m) {
                        if (A[m] != A[i]) continue;
                        ans = max(ans, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[0][N - 1][0];
    }
};