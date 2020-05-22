// OJ: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> dp(N + 1);
        for (int i = 0; i < M; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j) {
                int cur = dp[j + 1];
                if (A[i][j] == 0) dp[j + 1] = 0;
                else dp[j + 1] = min({ prev, dp[j], dp[j + 1] }) + 1;
                ans += dp[j + 1];
                prev = cur;
            }
        }
        return ans;
    }
};