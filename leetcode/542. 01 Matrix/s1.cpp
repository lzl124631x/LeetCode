// OJ: https://leetcode.com/problems/01-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return matrix;
    int M = matrix.size(), N = matrix[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (!matrix[i][j]) q.emplace(i, j);
        else matrix[i][j] = INT_MAX;
      }
    }
    int dirs[][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};
    while (q.size()) {
      auto p = q.front();
      q.pop();
      for (auto dir : dirs) {
        int x = p.first + dir[0], y = p.second + dir[1];
        if (x >= 0 && x < M && y >= 0 && y < N && matrix[x][y] == INT_MAX) {
          matrix[x][y] = matrix[p.first][p.second] + 1;
          q.emplace(x, y);
        }
      }
    }
    return matrix;
  }
};