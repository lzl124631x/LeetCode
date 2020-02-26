// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(mnN)
// Space: O(mn)
class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int mod = 1e9 + 7;
    int findPaths(int m, int n, int N, int x, int y) {
        if (!N) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2)));
        for (int i = 0; i < m; ++i) dp[i][0][1]++, dp[i][n - 1][1]++;
        for (int i = 0; i < n; ++i) dp[0][i][1]++, dp[m - 1][i][1]++;
        int ans = dp[x][y][1];
        for (int k = 2; k <= N; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = 0;
                    for (auto &dir : dirs) {
                        int a = i + dir[0], b = j + dir[1];
                        if (a < 0 || a >= m || b < 0 || b >= n) continue;
                        val = (val + dp[a][b][(k - 1) % 2]) % mod;
                    }
                    dp[i][j][k % 2] = val;
                    if (x == i && y == j) ans = (ans + val) % mod;
                }
            }
        }
        return ans;
    }
};