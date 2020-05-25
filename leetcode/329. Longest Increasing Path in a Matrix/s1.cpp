// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    vector<vector<int>> cnt;
    int ans = 0, M, N, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>> &A, int x, int y) {
        if (cnt[x][y]) return cnt[x][y];
        cnt[x][y] = 1;
        for (auto &dir : dirs) {
            int a = x + dir[0], b = y + dir[1];
            if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] <= A[x][y]) continue;
            cnt[x][y] = max(cnt[x][y], 1 + dfs(A, a, b));
        }
        return cnt[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        M = A.size(), N = A[0].size();
        cnt.assign(M, vector<int>(N));
        for (int i = 0; i < M; ++i) 
            for (int j = 0; j < N; ++j) 
                ans = max(ans, dfs(A, i, j));
        return ans;
    }
};