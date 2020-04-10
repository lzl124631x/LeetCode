// OJ: https://leetcode.com/problems/burst-balloons/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& A) {
        if (A.empty()) return 0;
        A.insert(A.begin(), 1);
        A.push_back(1);
        int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};