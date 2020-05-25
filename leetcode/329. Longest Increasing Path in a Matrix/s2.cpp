// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/288520/BFS-Implemented-Topological-Sort
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> indegree(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (auto &dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || x >= M || y < 0 || y >= N || A[x][y] <= A[i][j]) continue;
                    indegree[x][y]++;
                }
            }
        }
        queue<vector<int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (indegree[i][j] == 0) q.push({ i, j });
            }
        }
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                for (auto &dir : dirs) {
                    int a = x + dir[0], b = y + dir[1];
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] <= A[x][y]) continue;
                    if (--indegree[a][b] == 0) q.push({ a, b });
                }
            }
            ++ans;
        }
        return ans;
    }
};