// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Auther: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        if (j - i >= 1 && ((!k && !sum) || (k && sum % k == 0))) return true;
      }
    }
    return false;
  }
};