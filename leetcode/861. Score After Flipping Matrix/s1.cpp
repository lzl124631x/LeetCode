// OJ: https://leetcode.com/problems/score-after-flipping-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            if (A[i][0]) continue;
            for (int j = 0; j < N; ++j) A[i][j] = 1 - A[i][j];
        }
        for (int j = 1; j < N; ++j) {
            int one = 0;
            for (int i = 0; i < M; ++i) one += A[i][j];
            if (one * 2 >= M) continue;
            for (int i = 0; i < M; ++i) A[i][j] = 1 - A[i][j];
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) ans += A[i][j] * (1 << (N - j - 1));
        }
        return ans;
    }
};