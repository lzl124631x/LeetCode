// OJ: https://leetcode.com/problems/number-of-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& A, int x, int y) {
        if (x < 0 || y < 0 || x >= M || y >= N || A[x][y] != '1') return;
        A[x][y] = 'x';
        for (auto &dir : dirs) dfs(A, x + dir[0], y + dir[1]);
    }
public:
    int numIslands(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int ans = 0;
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != '1') continue;
                ++ans;
                dfs(A, i, j);
            }
        }
        return ans;
    }
};