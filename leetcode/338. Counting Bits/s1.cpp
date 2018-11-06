// OJ: https://leetcode.com/problems/counting-bits
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> ans(num + 1);
    for (int i = 1; i <= num; i *= 2) {
      ans[i] = 1;
      for (int j = 1; j < i && i + j <= num; ++j) ans[i + j] = ans[i] + ans[j];
    }
    return ans;
  }
};