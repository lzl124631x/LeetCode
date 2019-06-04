// OJ: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(MN)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size(), ans = 0;
        vector<vector<int>> sum(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int m = 0; m < i; ++m) {
                    for (int n = 0; n < j; ++n) {
                        if (sum[i][j] - sum[i][n] - sum[m][j] + sum[m][n] == target) ++ans;
                    }
                }
            }
        }
        return ans;
    }
};