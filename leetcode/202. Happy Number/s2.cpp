// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// The maximum number is 2^31 - 1, around 10^9, ie. has 10 digits.
// So the next number of it is at most 9*9*10=810, which has 3 digits.
// So the number of digits will drop significantly to less than 4 digits.
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