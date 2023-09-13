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
    unordered_set<int> nums;
    queue<pair<int, int>> q;
    while ((n = n % d * 10) && !nums.count(n)) {
      nums.insert(n);
      q.push({ n, n / d });
    }
    if (q.size()) ans += '.';
    while (q.size()) {
      if (q.front().first == n) ans += '(';
      ans += '0' + q.front().second;
      q.pop();
    }
    if (n) ans += ')';
    return ans;
  }
};