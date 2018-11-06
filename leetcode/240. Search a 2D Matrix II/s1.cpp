// OJ: https://leetcode.com/problems/search-a-2d-matrix-ii
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int M = matrix.size(), N = matrix[0].size(), i = 0, j = N - 1;
    while (i < M && j >= 0) {
      if (matrix[i][j] > target) --j;
      else if (matrix[i][j] < target) ++i;
      else return true;
    }
    return false;
  }
};