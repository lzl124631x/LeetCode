// OJ: https://leetcode.com/problems/unique-binary-search-trees
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < i; ++j) dp[i] += dp[j] * dp[i - j - 1];
    return dp[n];
  }
};