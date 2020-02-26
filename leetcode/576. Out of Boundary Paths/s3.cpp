// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(mnN)
// Space: O(mn)
// Ref: https://leetcode.com/problems/out-of-boundary-paths/solution/
class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    const int mod = 1e9 + 7;
public:
    int findPaths(int m, int n, int N, int x, int y) {
        if (!N) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2)));
        dp[x][y][1] = 1;
        int ans = 0;
        for (int k = 1; k <= N; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = dp[i][j][k % 2];
                    if (!i) ans = (ans + val) % mod;
                    if (i == m - 1) ans = (ans + val) % mod;
                    if (!j) ans = (ans + val) % mod;
                    if (j == n - 1) ans = (ans + val) % mod;
                    val = 0;
                    for (auto &dir : dirs) {
                        int a = i + dir[0], b = j + dir[1];
                        if (a < 0 || a >= m || b < 0 || b >= n) continue;
                        val = (val + dp[a][b][k % 2]) % mod;
                    }
                    dp[i][j][(k + 1) % 2] = val;
                }
            }
        }
        return ans; 
    }
};