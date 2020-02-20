// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> dp(2, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[(i + 1) % 2][j + 1] = A[i][j] == '0' ? 0 : min({ dp[i % 2][j], dp[i % 2][j + 1], dp[(i + 1) % 2][j] }) + 1;
                ans = max(ans, dp[(i + 1) % 2][j + 1]);
            }
        }
        return ans * ans;
    }
};