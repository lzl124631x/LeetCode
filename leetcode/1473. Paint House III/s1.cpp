// OJ: https://leetcode.com/contest/weekly-contest-192/problems/paint-house-iii/
// Author: github.com/lzl124631x
// Time: O(N^2 * MT)
// Space: O(MNT)
class Solution {
    vector<int> H;
    vector<vector<int>> C;
    int M, N, T, INF = 1e6;
    vector<vector<vector<int>>> memo;
    int dp(int i, int last, int cnt) {
        if (cnt > T) return INF;
        if (i == M) return cnt == T ? 0 : INF;
        if (memo[i][last][cnt] != -1) return memo[i][last][cnt];
        if (H[i]) return memo[i][last][cnt] = dp(i + 1, H[i], H[i] == last ? cnt : (cnt + 1));
        int ans = INF;
        for (int j = 0; j < N; ++j) ans = min(ans, C[i][j] + dp(i + 1, j + 1, j + 1 == last ? cnt : (cnt + 1)));
        return memo[i][last][cnt] = ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        H = houses, C = cost, M = m, N = n, T = target;
        memo.assign(M, vector<vector<int>>(N + 1, vector<int>(T + 1, -1)));
        int ans = dp(0, 0, 0);
        return ans == INF ? -1 : ans;
    }
};