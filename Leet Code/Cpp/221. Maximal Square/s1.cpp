class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int maxSize = 0;
        for (int i = 0; i < N; ++i) {
            dp[0][i] = matrix[0][i] - '0';
            maxSize = max(maxSize, dp[0][i]);
        }
        for (int i = 0; i < M; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            maxSize = max(maxSize, dp[i][0]);
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }
        return maxSize * maxSize;
    }
};