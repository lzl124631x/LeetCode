// OJ: https://leetcode.com/problems/super-ugly-number
// Author: github.com/lzl124631x
// Time: O(NP)
// Space: O(max(N, P))
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> v(n, INT_MAX), p(primes.size(), 0);
    v[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < primes.size(); ++j) v[i] = min(v[i], primes[j] * v[p[j]]);
      for (int j = 0; j < primes.size(); ++j) p[j] += (v[i] == primes[j] * v[p[j]]);
    }
    return v.back();
  }
};