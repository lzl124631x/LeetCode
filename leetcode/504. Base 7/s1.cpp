// OJ: https://leetcode.com/problems/base-7
// Author: github.com/lzl124631x
// Time: O(log_7^num)
// Space: O(1)
class Solution {
public:
  string convertToBase7(int num) {
    string ans;
    int x = abs(num);
    do { ans += '0' + (x % 7); } while (x /= 7);
    if (num < 0) ans += '-';
    reverse(ans.begin(), ans.end());
    return ans;
  }
};