// OJ: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: github.com/lzl124631x
// Time: O(min(M, N)^2 * (M + N))
// Space: O(1)
class Solution {
    int M, N, minMN;
    void bubbleSort(vector<vector<int>> &v, int sx, int sy) {
        for (int i = 0; i < minMN; ++i) {
            int ix = sx + i, iy = sy + i;
            if (ix >= M || iy >= N) return;
            for (int j = minMN - 1; j > i; --j) {
                int jx = sx + j, jy = sy + j;
                if (jx >= M || jy  >= N) continue;
                if (jx - 1 < 0 || jy - 1 < 0) break;
                if (v[jx][jy] < v[jx - 1][ jy - 1]) swap(v[jx][jy] ,v[jx - 1][ jy - 1]);
            }
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        M = mat.size(), N = mat[0].size(), minMN = min(M, N);
        for (int i = 0; i < N; ++i) bubbleSort(mat, 0, i);
        for (int i = 1; i < M; ++i) bubbleSort(mat, i, 0);            
        return mat;
    }
};