// OJ: https://leetcode.com/problems/super-ugly-number
// Author: github.com/lzl124631x
// Time: O(NP)
// Space: O(max(N, P))
// Ref: https://discuss.leetcode.com/topic/34841/java-three-methods-23ms-36-ms-58ms-with-heap-performance-explained
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> v(n, INT_MAX), p(primes.size(), 0), val(primes.size(), 1);
    v[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < primes.size(); ++j) {
        if (v[i - 1] == val[j]) val[j] = v[p[j]++] * primes[j];
        v[i] = min(v[i], val[j]);
      }
    }
    return v[n - 1];
  }
};