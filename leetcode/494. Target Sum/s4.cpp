// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(S)
// Ref: https://discuss.leetcode.com/topic/76243/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation
class Solution {
private:
  int subsetSum(vector<int> &nums, int S) {
    vector<int> dp(S + 1, 0);
    dp[0] = 1;
    for (int n : nums)
      for (int i = S; i >= n; --i) dp[i] += dp[i - n];
    return dp[S];
  }
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum < S || (sum + S) % 2 ? 0 : subsetSum(nums, (sum + S) / 2);
  }
};