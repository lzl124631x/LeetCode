// OJ: https://leetcode.com/problems/minimum-falling-path-sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        vector<vector<int>> dp(2, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[(i + 1) % 2][j] = A[i][j] + min(j - 1 >= 0 ? dp[i % 2][j - 1] : INT_MAX,
                                   min(dp[i % 2][j],
                                       j + 1 < N ? dp[i % 2][j + 1] : INT_MAX));
            }
        }
        return *min_element(dp[N % 2].begin(), dp[N % 2].end());
    }
};