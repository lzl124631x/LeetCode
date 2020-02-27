// OJ: https://leetcode.com/problems/number-of-paths-with-max-score/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
    const int mod = 1e9 + 7;
public:
    vector<int> pathsWithMaxScore(vector<string>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> zero(2, 0);
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(N, vector<int>(2, 0)));
        dp[(M - 1) % 2][N - 1][1] = 1;
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (A[i][j] == 'S') dp[i % 2][j] = { 0, 1 };
                else if (A[i][j] == 'X') dp[i % 2][j] = zero;
                else {
                    int sum = 0, cnt = 0;
                    auto &B = i + 1 < M ? dp[(i + 1) % 2][j] : zero;
                    auto &R = j + 1 < N ? dp[i % 2][j + 1] : zero;
                    auto &BR = i + 1 < M && j + 1 < N ? dp[(i + 1) % 2][j + 1] : zero;
                    sum = max({ B[0], R[0], BR[0] });
                    if (B[0] == sum) cnt = (cnt + B[1]) % mod;
                    if (R[0] == sum) cnt = (cnt + R[1]) % mod;
                    if (BR[0] == sum) cnt = (cnt + BR[1]) % mod;
                    dp[i % 2][j] = { sum, cnt };
                }
                if (dp[i % 2][j][1] && isdigit(A[i][j])) dp[i % 2][j][0] += A[i][j] - '0';
            }
        }
        return dp[0][0];
    }
};