// OJ: https://leetcode.com/problems/lucky-numbers-in-a-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M + N)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<int> row(M, INT_MAX), col(N, INT_MIN);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                row[i] = min(row[i], A[i][j]);
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                col[i] = max(col[i], A[j][i]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == row[i] && A[i][j] == col[j]) ans.push_back(A[i][j]);
            }
        }
        return ans;
    }
};