// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
  int M, N, ans = 0, dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> cnt;
  int dfs(vector<vector<int>> &matrix, int x, int y) {
    if (cnt[x][y]) return cnt[x][y];
    cnt[x][y] = 1;
    for (auto dir : dirs) {
      int i = x + dir[0], j = y + dir[1];
      if (i < 0 || i >= M || j < 0 || j >= N || matrix[i][j] <= matrix[x][y]) continue;
      cnt[x][y] = max(cnt[x][y], 1 + dfs(matrix, i, j));
    }
    ans = max(ans, cnt[x][y]);
    return cnt[x][y];
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    M = matrix.size(), N = matrix[0].size();
    cnt = vector<vector<int>> (M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        dfs(matrix, i, j);
    return ans;
  }
};