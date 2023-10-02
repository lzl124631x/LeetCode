// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(N^2 * D)
// Space: O(N^2 + ND)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int minDifficulty(vector<int>& A, int D) {
        int N = A.size();
        if (D > N) return -1;
        vector<vector<LL>> mx(N, vector<LL>(N)), dp(D + 1, vector<LL>(N, 1e9));
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) mx[i][j] = *max_element(A.begin() + i, A.begin() + j + 1);
        }
        for (int i = 0; i < N; ++i) dp[1][i] = mx[0][i];
        for (int d = 2; d <= D; ++d) {
            for (int i = d - 1; i < N; ++i) {
                for (int j = d - 1; j <= i; ++j) {
                    setMin(dp[d][i], dp[d - 1][j - 1] + mx[j][i]);
                }
            }
        }
        return dp[D][N - 1];
    }
};