// OJ: https://leetcode.com/problems/fraction-to-recurring-decimal
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    long long n = numerator, d = denominator;
    string ans;
    if ((n > 0 && d < 0) || (n < 0 && d > 0)) ans += '-';
    n = abs(n);
    d = abs(d);
    ans += to_string(n / d);
    if (n % d) ans += '.';
    unordered_map<int, int> numToIndex;
    while ((n = n % d * 10) && !numToIndex.count(n)) {
      numToIndex[n] = ans.size();
      ans += '0' + n / d;
    }
    if (n) {
      ans.insert(numToIndex[n], 1, '(');
      ans += ')';
    }
    return ans;
  }
};