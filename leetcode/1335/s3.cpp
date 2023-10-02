// OJ: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: github.com/lzl124631x
// Time: O(NND)
// Space: O(N)
class Solution {
    typedef long long LL;
    inline void setMin(LL &a, LL b) { a = min(a, b); }
public:
    int minDifficulty(vector<int>& A, int D) {
        int N = A.size(), inf = 1e9;
        if (D > N) return -1;
        vector<LL> dp(N);
        for (int i = 0; i < N; ++i) dp[i] = i == 0 ? A[0] : max(dp[i - 1], (LL)A[i]);
        for (int d = 2; d <= D; ++d) {
            for (int i = N - 1; i >= d - 1; --i) {
                int mx = 0;
                dp[i] = inf;
                for (int j = i; j >= d - 1; --j) {
                    mx = max(mx, A[j]);
                    setMin(dp[i], dp[j - 1] + mx);
                }
            }
        }
        return dp[N - 1];
    }
};