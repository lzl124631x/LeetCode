// OJ: https://leetcode.com/problems/maximum-students-taking-exam/
// Author: github.com/lzl124631x
// Time: O(M * (2^N)^2)
// Space: O(M * 2^N)
// Ref: https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem
class Solution {
public:
    int maxStudents(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> states;
        for (int i = 0; i < M; ++i) {
            int cur = 0;
            for (int j = 0; j < N; ++j) cur = cur * 2 + (A[i][j] == '.');
            states.push_back(cur);
        }
        vector<vector<int>> dp(M + 1, vector<int>(1 << N, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= M; ++i) {
            int state = states[i - 1];
            for (int j = 0; j < (1 << N); ++j) {
                if ((j & state) != j || (j & (j >> 1))) continue;
                int cnt = __builtin_popcount(j);
                for (int k = 0; k < (1 << N); ++k) {
                    if ((j & (k >> 1)) || (j & (k << 1)) || dp[i - 1][k] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);
                }
            }
        }
        return *max_element(begin(dp[M]), end(dp[M]));
    }
};