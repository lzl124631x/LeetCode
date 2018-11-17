// OJ: https://leetcode.com/problems/toeplitz-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        for (int i = 0; i < M; ++i) {
            for (int x = i + 1, y = 1; x < M && y < N; ++x, ++y) {
                if (matrix[x][y] != matrix[x - 1][y - 1]) return false;
            }
        }
        for (int i = 1; i < N; ++i) {
            for (int x = 1, y = i + 1; x < M && y < N; ++x, ++y) {
                if (matrix[x][y] != matrix[x - 1][y - 1]) return false;
            }
        }
        return true;
    }
};