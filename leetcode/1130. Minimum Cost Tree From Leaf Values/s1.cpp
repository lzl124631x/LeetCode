// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> mx(N, vector<int>(N)), dp(N, vector<int>(N, INT_MAX));
        for (int i = 0; i < N; ++i) {
            mx[i][i] = A[i];
            for (int j = i + 1; j < N; ++j) mx[i][j] = max(mx[i][j - 1], A[j]);
        }  
        for (int i = 0; i < N; ++i) dp[i][i] = 0;
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mx[i][k] * mx[k + 1][j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};