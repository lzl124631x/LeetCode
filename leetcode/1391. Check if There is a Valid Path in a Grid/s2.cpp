// OJ: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://www.youtube.com/watch?v=SpMez87v0O8
class Solution {
    int M, N;
    vector<vector<int>> A;
    vector<vector<bool>> vis;
    int h(int x, int y) { return x * N + y; }
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1}, t[6] = {4|8, 1|2, 8|1, 4|1, 8|2, 4|2};
    bool dfs(int i, int j) {
        if (i == M - 1 && j == N - 1) return 1;
        vis[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            if (t[A[i][j] - 1] >> k & 1 ^ 1) continue; // If A[i][j] can't extend to this direction, skip
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= M || y < 0 || y >= N || vis[x][y]) continue;
            int rk = k ^ 1;
            if (t[A[x][y] - 1] >> rk & 1 ^ 1) continue; // If A[x][y] can't extend back, skip
            if (dfs(x, y)) return 1;
        }
        return 0;
    }
public:
    bool hasValidPath(vector<vector<int>>& A) {
        M = A.size(), N = A[0].size();
        this->A = A;
        vis.assign(M, vector<bool>(N));
        return dfs(0, 0);
    }
};