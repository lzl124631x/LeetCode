// OJ: https://leetcode.com/problems/game-of-life/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    int M, N;
    inline bool alive(vector<vector<int>> &A, int x, int y) {
        return x >= 0 && y >= 0 && x < M && y < N && A[x][y] & 1;
    }
public:
    void gameOfLife(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return;
        int dx[8] = {-1,-1,0,1,1,1,0,-1}, dy[8] = {0,1,1,1,0,-1,-1,-1};
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) cnt += alive(A, i + dx[k], j + dy[k]);
                if ((A[i][j] && cnt == 2) || cnt == 3) A[i][j] |= 2;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] >>= 1;
            }
        }
    }
};