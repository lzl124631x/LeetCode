// OJ: https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
  int longestLine(vector<vector<int>>& mtx) {
    if (mtx.empty() || mtx[0].empty()) return 0;
    int M = mtx.size(), N = mtx[0].size();
    int maxLen = 0;
    for (int i = 0; i < M; ++i) {
      int len = 0;
      for (int j = 0; j < N; ++j) {
        if (mtx[i][j] == 1) ++len;
        else len = 0;
        maxLen = max(maxLen, len);
      }
    }
    for (int i = 0; i < N; ++i) {
      int len = 0;
      for (int j = 0; j < M; ++j) {
        if (mtx[j][i] == 1) ++len;
        else len = 0;
        maxLen = max(maxLen, len);
      }
    }
    for (int x = 0, y = N - 1; x < M; ) {
      int len = 0;
      for (int i = x, j = y; i < M && j < N; ++i, ++j) {
        if (mtx[i][j] == 1) ++len;
        else len = 0;
        maxLen = max(maxLen, len);
      }
      if (y) --y;
      else ++x;
    }
    for (int x = M - 1, y = N - 1; y >= 0; ) {
      int len = 0;
      for (int i = x, j = y; i < M && j >= 0; ++i, --j) {
        if (mtx[i][j] == 1) ++len;
        else len = 0;
        maxLen = max(maxLen, len);
      }
      if (x) --x;
      else --y;
    }
    return maxLen;
  }
};