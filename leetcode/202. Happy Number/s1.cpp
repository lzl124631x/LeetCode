// Author: github.com/lzl124631x
// Time: O(Nk)
// Space: O(N)
// Where N is the length of transformation chain,
// k is the average length of numbers in the chain.
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