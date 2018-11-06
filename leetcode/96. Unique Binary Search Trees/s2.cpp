// OJ: https://leetcode.com/problems/unique-binary-search-trees
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/13321/a-very-simple-and-straight-ans-based-on-math-catalan-number-o-n-times-o-1-space
class Solution {
public:
  int numTrees(int n) {
    long long ans = 1, i;
    for (i = 1; i <= n; ++i) ans = ans * (i + n) / i;
    return ans / i;
  }
};