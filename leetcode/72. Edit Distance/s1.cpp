// OJ: https://leetcode.com/problems/edit-distance
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string A, string B) {
        if (A.empty() || B.empty()) return max(A.size(), B.size());
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) dp[i + 1][0] = i + 1;
        for (int j = 0; j < N; ++j) dp[0][j + 1] = j + 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j];
                else dp[i + 1][j + 1] = 1 + min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j]));
            }
        }
        return dp[M][N];
    }
};