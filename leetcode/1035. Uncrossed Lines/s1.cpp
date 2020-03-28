// OJ: https://leetcode.com/problems/uncrossed-lines/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i + 1][j + 1] = max({ dp[i][j + 1], dp[i + 1][j], A[i] == B[j] ? 1 + dp[i][j] : 0 });
            }
        }
        return dp[M][N];
    }
};