// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
  int happify(int n) {
    int next = 0;
    for (; n; next += pow(n % 10, 2), n /= 10);
    return next;
  }
public:
  bool isHappy(int n) {
    int slow = n, fast = n;
    do {
      slow = happify(slow);
      fast = happify(happify(fast));
    } while (slow != fast && fast != 1);
    return fast == 1;
  }
};