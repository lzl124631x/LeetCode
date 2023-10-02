// OJ: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& E, int k) {
        vector<vector<int>> d(n, vector<int>(n, (int) 1e6));
        for (int i = 0; i < n; ++i) d[i][i] = 0;
        for (auto &e : E) {
            d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    d[u][v] = min(d[u][v], d[u][i] + d[i][v]);
                }
            }
        }
        int ans = 0, minCnt = n;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (d[i][j] <= k) ++cnt;
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};