// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(N^2 * D)
// Space: O(ND) 
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int minDifficulty(vector<int>& A, int D) {
        int N = A.size(), inf = 1e9;
        if (D > N) return -1;
        vector<vector<LL>> dp(D + 1, vector<LL>(N, inf));
        for (int i = 0; i < N; ++i) dp[1][i] = i == 0 ? A[0] : max(dp[1][i - 1], (LL)A[i]);
        for (int d = 2; d <= D; ++d) {
            for (int i = d - 1; i < N; ++i) {
                int mx = 0;
                for (int j = i; j >= d - 1; --j) {
                    mx = max(mx, A[j]);
                    setMin(dp[d][i], dp[d - 1][j - 1] + mx);
                }
            }
        }
        return dp[D][N - 1];
    }
};