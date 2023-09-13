// OJ: https://leetcode.com/problems/ugly-number-ii
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
  bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
  }
};