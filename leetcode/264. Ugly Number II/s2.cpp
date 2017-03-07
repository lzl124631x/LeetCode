// OJ: https://leetcode.com/problems/ugly-number-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> num(n, 1), index(3, 0), val{ 2, 3, 5 };
    for (int i = 1; i < n; ++i) {
      int next = INT_MAX;
      for (int j = 0; j < 3; ++j) next = min(next, num[index[j]] * val[j]);
      for (int j = 0; j < 3; ++j)
        if (num[index[j]] * val[j] == next) ++index[j];
      num[i] = next;
    }
    return num.back();
  }
};