// OJ: https://leetcode.com/problems/first-bad-version
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
  int firstBadVersion(int n) {
    int L = 1, R = n;
    while (L <= R) {
      int M = L + (R - L) / 2;
      if (isBadVersion(M)) R = M - 1;
      else L = M + 1;
    }
    return L;
  }
};