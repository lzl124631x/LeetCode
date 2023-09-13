// OJ: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                dp[i + 1][j + 1] = min({dp[i][j], dp[i + 1][j], dp[i][j + 1] }) + 1;
                ans += dp[i + 1][j + 1];
            }
        }
        return ans;
    }
};