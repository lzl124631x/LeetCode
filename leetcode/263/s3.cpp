// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
  bool isUgly(int num) {
    for (int i = 2; i < 6 && num > 0; ++i)
      while (num % i == 0) num /= i;
    return num == 1;
  }
};