// OJ: https://leetcode.com/problems/next-greater-element-iii
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/85740/c-4-lines-next_permutation
class Solution {
public:
    int nextGreaterElement(int n) {
      auto digits = to_string(n);
      next_permutation(begin(digits), end(digits));
      auto ans = stol(digits);
      return (ans > INT_MAX || ans <= n) ? -1 : ans;
    }
};