// OJ: https://leetcode.com/problems/cherry-pickup-ii/
// Author: github.com/lzl124631x
// Time: O(M * N^2)
// Space: O(M * N^2)
class Solution {
    int m[70][70][70], M, N;
    int dp(vector<vector<int>> & A, int i, int a, int b) {
        if (i == M) return 0;
        if (m[i][a][b] != -1) return m[i][a][b];
        int v = a == b ? A[i][a] : (A[i][a] + A[i][b]);
        int ans = 0;
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                int p = a + x, q = b + y;
                if (p < 0 || q < 0 || p >= N || q >= N) continue;
                ans = max(ans, dp(A, i + 1, p, q));
            }
        }
        return m[i][a][b] = v + ans;
    }
public:
    int cherryPickup(vector<vector<int>>& A) {
        M = A.size(), N = A[0].size();
        memset(m, -1, sizeof(m));
        return dp(A, 0, 0, N - 1);
    }
};