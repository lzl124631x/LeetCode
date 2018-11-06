// OJ: https://leetcode.com/problems/search-a-2d-matrix
// Author: github.com/lzl124631x
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int M = matrix.size(), N = matrix[0].size();
    int L = 0, R = M - 1, row;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (matrix[mid][0] > target) R = mid - 1;
      else L = mid + 1;
    }
    if ((row = R) < 0) return false;
    L = 0, R = N - 1;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (matrix[row][mid] >= target) R = mid - 1;
      else L = mid + 1;
    }
    return L < N && matrix[row][L] == target;
  }
};