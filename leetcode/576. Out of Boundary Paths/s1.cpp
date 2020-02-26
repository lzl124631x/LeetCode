// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/lzl124631x
// Time: O(mnN)
// Space: O(mnN)
typedef long long LL;
class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int mod = 1e9 + 7;
    inline int hash(int x, int y, int n) { return 10000 * x + 100 * y + n; }
    unordered_map<int, int> dp;
    int dfs(int m, int n, int N, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (!N) return 0;
        int key = hash(i, j, N);
        if (dp.count(key)) return dp[key];
        LL cnt = 0;
        for (auto &dir : dirs) cnt = (cnt + dfs(m, n, N - 1, i + dir[0], j + dir[1])) % mod;
        return dp[key] = cnt;
    }
public:
    int findPaths(int m, int n, int N, int i, int j) {
        return dfs(m, n, N, i, j);
    }
};