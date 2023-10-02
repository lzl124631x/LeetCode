// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while (n != 1 && !s.count(n)) {
      s.insert(n);
      int next = 0;
      while (n) {
        next += pow(n % 10, 2);
        n /= 10;
      }
      n = next;
    }
    return n == 1;
  }
};