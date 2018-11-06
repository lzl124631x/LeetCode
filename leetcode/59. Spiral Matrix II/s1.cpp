// OJ: https://leetcode.com/problems/spiral-matrix-ii
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0, d = 1; i < (n + 1) / 2; ++i) {
      for (int j = i; j < n - i; ++j) ans[i][j] = d++;
      for (int j = i + 1; j < n - i; ++j) ans[j][n - i - 1] = d++;
      for (int j = n - i - 2; n - i - 1 != i && j >= i; --j) ans[n - i - 1][j] = d++;
      for (int j = n - i - 2; n - i - 1 != i && j > i; --j) ans[j][i] = d++;
    }
    return ans;
  }
};