// OJ: https://leetcode.com/problems/next-greater-element-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/85740/c-4-lines-next_permutation
int nextGreaterElement(int n) {
  auto digits = to_string(n);
  next_permutation(begin(digits), end(digits));
  auto res = stoll(digits);
  return (res > INT_MAX || res <= n) ? -1 : res;
}