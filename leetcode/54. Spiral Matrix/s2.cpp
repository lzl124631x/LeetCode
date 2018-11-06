// OJ: https://leetcode.com/problems/spiral-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    vector<int> ans;
    int M = matrix.size(), N = matrix[0].size(), xl = 0, xh = M - 1, yl = 0, yh = N - 1;
    while (xl <= xh && yl <= yh) {
      int x = xl, y = yl;
      if (xl == xh) {
        while (y <= yh) ans.push_back(matrix[x][y++]);
        break;
      } else if (yl == yh) {
        while (x <= xh) ans.push_back(matrix[x++][y]);
        break;
      } else {
        while (y < yh) ans.push_back(matrix[x][y++]);
        --yh;
        while (x < xh) ans.push_back(matrix[x++][y]);
        --xh;
        while (y > yl) ans.push_back(matrix[x][y--]);
        ++yl;
        while (x > xl) ans.push_back(matrix[x--][y]);
        ++xl;
      }
    }
    return ans;
  }
};