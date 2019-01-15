// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
  int next(int n) {
    int ans = 0;
    for (; n; ans += pow(n % 10, 2), n /= 10);
    return ans;
  }
public:
  bool isHappy(int n) {
    for (; n != 1 && n != 4; n = next(n));
    return n == 1;
  }
};