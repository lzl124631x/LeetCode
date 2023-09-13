// OJ: https://leetcode.com/contest/weekly-contest-188/problems/number-of-ways-of-cutting-a-pizza/
// Author: github.com/lzl124631x
// Time: O(MNK * max(M, N))
// Space: O(MNK)
class Solution {
    void add(long &a, long &b) { a = (a + b) % ((int) 1e9+7); }
public:
    int ways(vector<string>& A, int K) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> cnt(M + 1, vector<int>(N + 1));
        for (int i = M - 1; i >= 0; --i) {
            int s = 0;
            for (int j = N - 1; j >= 0; --j) {
                s += A[i][j] == 'A';
                cnt[i][j] = cnt[i + 1][j] + s;
            }
        }
        vector<vector<vector<long>>> dp(M + 1, vector<vector<long>>(N + 1, vector<long>(K + 1)));
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                dp[i][j][1] = 1;
                for (int k = 2; k <= K; ++k) {
                    for (int t = i + 1; t < M; ++t) {
                        if (cnt[i][j] == cnt[t][j]) continue;
                        if (cnt[t][j] == 0) break;
                        add(dp[i][j][k], dp[t][j][k - 1]);
                    }
                    for (int t = j + 1; t < N; ++t) {
                        if (cnt[i][j] == cnt[i][t]) continue;
                        if (cnt[i][t] == 0) break;
                        add(dp[i][j][k], dp[i][t][k - 1]);
                    }
                }
            }
        }
        return dp[0][0][K];
    }
};