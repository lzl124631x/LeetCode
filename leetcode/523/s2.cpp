// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        nums[j] += nums[i];
        if (k) nums[j] %= k;
        if (!nums[j]) return true;
      }
    }
    return false;
  }
};