// OJ: https://leetcode.com/problems/partition-equal-subset-sum
// Author: github.com/lzl124631x
// Time: O(NS)
// Space: O(S) where S the sum of nums.
class Solution {
private:
  bool subsetSum(vector<int> &nums, int S) {
    vector<int> dp(S + 1);
    dp[0] = 1;
    for (int n : nums)
      for (int i = S; i >= n; --i) dp[i] += dp[i - n];
    return dp[S];
  }
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum % 2 == 0 && subsetSum(nums, sum / 2);
  }
};