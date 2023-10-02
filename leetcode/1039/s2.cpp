// OJ: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int len = 3; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int val = INT_MAX;
                for (int k = i + 1; k < i + len - 1; ++k) {
                    val = min(val, dp[i][k] + dp[k][i + len - 1] + A[i] * A[i + len - 1] * A[k]);
                }
                dp[i][i + len - 1] = val;
            }
        }
        return dp[0][N - 1];
    }
};