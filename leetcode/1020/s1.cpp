// OJ: https://leetcode.com/problems/number-of-enclaves/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int M, N;
    void dfs(vector<vector<int>> &A, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || !A[x][y]) return;
        A[x][y] = 0;
        for (auto &dir : dirs) dfs(A, x + dir[0], y + dir[1]);
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        M = A.size(), N = A[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) dfs(A, i, 0), dfs(A, i, N - 1);
        for (int i = 0; i < N; ++i) dfs(A, 0, i), dfs(A, M - 1, i);
        for (auto &row : A) {
            for (int n : row) {
                if (n) ++ans;
            }
        }
        return ans;
    }
};