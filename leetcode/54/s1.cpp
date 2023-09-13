// OJ: https://leetcode.com/problems/spiral-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    vector<int> ans;
    int M = matrix.size(), N = matrix[0].size();
    for (int i = 0; ans.size() < M * N; ++i) {
      for (int j = i; j < N - i; ++j) ans.push_back(matrix[i][j]);
      for (int j = i + 1; j < M - i; ++j) ans.push_back(matrix[j][N - i - 1]);
      for (int j = N - i - 2; M - i - 1 != i && j >= i; --j) ans.push_back(matrix[M - i - 1][j]);
      for (int j = M - i - 2; N - i - 1 != i && j > i; --j) ans.push_back(matrix[j][i]);
    }
    return ans;
  }
};