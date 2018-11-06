// OJ: https://leetcode.com/problems/contiguous-array
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int start = i - dp[i];
      if (start > 0 && nums[start - 1] != nums[i]) {
        dp[i + 1] = dp[i] + 2 + dp[start - 1];
      } else {
        for (int diff = 0; start <= i && diff != 1; ++start) {
          if (nums[start] == nums[i]) diff++;
          else diff--;
        }
        dp[i + 1] = i - start + 1;
      }
      ans = max(ans, dp[i + 1]);
    }
    return ans;
  }
};