// OJ: https://leetcode.com/problems/cherry-pickup-ii/
// Author: github.com/lzl124631x
// Time: O(M * N^2)
// Space: O(N^2)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> d(N, vector<int>(N, -1)), e(N, vector<int>(N));
        d[0][N - 1] = A[0][0] + A[0][N - 1];
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) e[j][k] = -1;
            }
            for (int j = 0; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    if (d[j][k] < 0) continue;
                    for (int a = -1; a <= 1; ++a) {
                        int s = j + a;
                        if (s < 0 || s >= N) continue;
                        for (int b = -1; b <= 1; ++b) {
                            int t = k + b;
                            if (t < 0 || t >= N) continue;
                            int val = s == t ? A[i][s] : (A[i][s] + A[i][t]);
                            e[s][t] = max(e[s][t], d[j][k] + val);
                        }
                    }
                }
            }
            swap(d, e);
        }
        for (int j = 0; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) ans = max(ans, d[j][k]);
        }
        return ans;
    }
};