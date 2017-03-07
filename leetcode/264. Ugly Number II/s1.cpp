// OJ: https://leetcode.com/problems/ugly-number-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> v(n);
    v[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; ++i) {
      v[i] = min(v[i2] * 2, min(v[i3] * 3, v[i5] * 5));
      if (v[i] == v[i2] * 2) ++i2;
      if (v[i] == v[i3] * 3) ++i3;
      if (v[i] == v[i5] * 5) ++i5;
    }
    return v[n - 1];
  }
};