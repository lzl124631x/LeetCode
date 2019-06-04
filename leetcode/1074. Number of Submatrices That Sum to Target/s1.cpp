// OJ: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// Author: github.com/lzl124631x
// Time: O(M * N^2)
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
        for (int i = 0; i < N; ++i) {
           for (int j = i + 1; j <= N; ++j) {
               unordered_map<int, int> m {{ 0, 1 }};
               for (int k = 1; k <= M; ++k) {
                   int val = sum[k][j] - sum[k][i];
                   ans += m[val - target];
                   m[val]++;
               }
           }
        }
        return ans;
    }
};