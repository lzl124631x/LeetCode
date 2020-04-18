// OJ: https://leetcode.com/problems/number-of-islands/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    int M, N;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<char>> &A, int x, int y) {
        queue<pair<int, int>> q;
        q.emplace(x, y);
        A[x][y] = 'x';
        while (q.size()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            for (auto &dir : dirs) {
                int i = x + dir[0], j = y + dir[1];
                if (i < 0 || j < 0 || i >= M || j >= N || A[i][j] != '1') continue;
                A[i][j] = 'x';
                q.emplace(i, j);
            }
        }
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
                bfs(A, i, j);
            }
        }
        return ans;
    }
};