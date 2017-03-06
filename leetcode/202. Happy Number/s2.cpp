// Author: lzl
// Time: O(Nk)
// Space: O(1)
// Where N is the length of transformation chain,
// k is the average length of numbers in the chain.
// Detail: fast & slow pointers.
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