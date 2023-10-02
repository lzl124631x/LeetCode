// OJ: https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix
// Author: github.com/lzl124631x
// Time: O(MN * max(M, N))
// Space: O(1)
class Solution {
private:
    bool valid(vector<vector<int>>& M, int x, int y) {
      return x >= 0 && x < M.size() && y >= 0 && y < M[0].size() && M[x][y];
    }
public:
  int longestLine(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return 0;
    int m = M.size(), n = M[0].size(), maxLen = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!valid(M, i, j)) continue;
        for (int k = -1; k <= 1; ++k) {
          for (int l = -1; l <= 1; ++l) {
            if ((!k && !l) || valid(M, i - k, j - l)) continue;
            int len = 0;
            for (int x = i, y = j; valid(M, x, y); x += k, y += l, ++len);
            maxLen = max(maxLen, len);
          }
        }
      }
    }
    return maxLen;
  }
};