// OJ: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    typedef unsigned long long ULL;
    int N, mod = 1e9+7;
    unordered_map<int, ULL> m;
    int key(vector<vector<int>> &v, int x) {
        if (x == -1) return 0;
        int n = 0;
        for (int i = 0; i < 3; ++i) n = n * 10 + v[x][i];
        n *= 10000;
        return n + x;
    }
    int dp(vector<vector<int>> &v, int x, int y) {
        if (y >= 3) {
            x++;
            y = 0;
        }
        if (x == N) return 1;
        int k = key(v, x - 1);
        if (y == 0 && m.count(k)) return m[k];
        int cnt = 0;
        for (int i = 1; i <= 3; ++i) {
            if ((x > 0 && v[x - 1][y] == i) || (y > 0 && v[x][y - 1] == i)) continue;
            v[x][y] = i;
            cnt = (cnt + dp(v, x, y + 1)) % mod;
        }
        if (y == 0) m[k] = cnt;
        return cnt;
    }
public:
    int numOfWays(int n) {
        N = n;
        vector<vector<int>> v(n, vector<int>(3));
        return dp(v, 0, 0);
    }
};