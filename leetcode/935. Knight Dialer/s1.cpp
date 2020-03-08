// OJ: https://leetcode.com/problems/knight-dialer/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    vector<vector<int>> next {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
public:
    int knightDialer(int N) {
        vector<vector<int>> dp(2, vector<int>(10, 1));
        int mod = 1e9 + 7, ans = 0;
        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j <= 9; ++j) {
                dp[i % 2][j] = 0;
                for (int n : next[j]) {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][n]) % mod;
                }
            }
        }
        for (int i = 0; i <= 9; ++i) ans = (ans + dp[N % 2][i]) % mod;
        return ans;
    }
};