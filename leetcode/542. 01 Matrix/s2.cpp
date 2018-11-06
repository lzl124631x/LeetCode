// OJ: https://leetcode.com/problems/01-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/83472/18-line-c-dp-solution-o-n-easy-to-understand
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return matrix;
    int M = matrix.size(), N = matrix[0].size();
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (matrix[i][j])  matrix[i][j] = INT_MAX;
      }
    }
    int dirs[][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};
    for (int t = 0; t <= 1; ++t) {
      for (int i = t ? 0 : M - 1; t ? i < M : i >= 0; t ? ++i : --i) {
        for (int j = t ? 0 : N - 1; t ? j < N : j >= 0; t ? ++j : --j) {
          if (!matrix[i][j]) continue;
          for (auto d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < M && y >= 0 && y < N && matrix[x][y] != INT_MAX)
              matrix[i][j] = min(matrix[i][j], matrix[x][y] + 1);
          }
        }
      }
    }
    return matrix;
  }
};