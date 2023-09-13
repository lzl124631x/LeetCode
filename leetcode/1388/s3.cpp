// OJ: https://leetcode.com/problems/pizza-with-3n-slices/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int solve(vector<int> A, int cnt) {
        int N = A.size();
        vector<vector<int>> dp(2, vector<int>(N + 1, -1e9));
        for (int i = 0; i < N + 1; ++i) dp[0][i] = 0;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i > j / 2 + 1) dp[i % 2][j + 1] = -1e9;
                else dp[i % 2][j + 1] = max(dp[i % 2][j], (j == 0 ? 0 : dp[(i - 1) % 2][j - 1]) + A[j]);
            }
        }
        return dp[cnt % 2][N];
    }
public:
    int maxSizeSlices(vector<int>& A) {
        int N = A.size(), ans = 0;
        return max(solve(vector<int>(A.begin(), A.end() - 1), N / 3),
                    solve(vector<int>(A.begin() + 1, A.end()), N / 3));
    }
};