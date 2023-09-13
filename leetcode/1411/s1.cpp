// OJ: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574912/JavaC%2B%2B-DFS-Memoization-with-Picture-Clean-code
class Solution {
    int memo[5001][4][4][4] = {0}, mod = 1e9+7;
    int dp(int n, int a, int b, int c) {
        if (n == 0) return 1;
        if (memo[n][a][b][c]) return memo[n][a][b][c];
        int ans = 0, colors[3] = {1, 2, 3};
        for (int aa : colors) {
            if (aa == a) continue;
            for (int bb : colors) {
                if (bb == b || bb == aa) continue;
                for (int cc : colors) {
                    if (cc == c || cc == bb) continue;
                    ans = (ans + dp(n - 1, aa, bb, cc)) % mod;
                }
            }
        }
        return memo[n][a][b][c] = ans;
    }
public:
    int numOfWays(int n) {
        return dp(n, 0, 0, 0);
    }
};