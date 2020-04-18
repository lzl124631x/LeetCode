// OJ: https://leetcode.com/problems/minimum-path-sum/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size();
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (i == M - 1 && j == N - 1) continue;
                if (i == M - 1) A[i][j] += A[i][j + 1];
                else if (j == N - 1) A[i][j] += A[i + 1][j];
                else A[i][j] += min(A[i][j + 1], A[i + 1][j]);
            }
        }
        return A[0][0];
    }
};