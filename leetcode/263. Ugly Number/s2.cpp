// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
  const vector<int> divisors{ 2, 3, 5 };
public:
  bool isUgly(int num) {
    for (int d : divisors)
      while (num > 0 && num % d == 0) num /= d;
    return num == 1;
  }
};