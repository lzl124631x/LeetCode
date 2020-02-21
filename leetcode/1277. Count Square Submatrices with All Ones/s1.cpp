// OJ: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0, M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int n = matrix[i][j] == 1 ? min({ dp[i % 2][j], dp[(i + 1) % 2][j], dp[i % 2][j + 1] }) + 1 : 0;
                ans += dp[(i + 1) % 2][j + 1] = n;
            }
        }
        return ans;
    }
};