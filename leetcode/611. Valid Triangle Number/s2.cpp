// OJ: https://leetcode.com/problems/valid-triangle-number
// Author: github.com/lzl124631x
// Time: O(N^2logN)
// Space: O(1)
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int cnt = 0, N = nums.size();
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        auto left = upper_bound(nums.begin() + j + 1, nums.end(), nums[j] - nums[i]);
        auto right = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
        if (right > left) cnt += right - left;
      }
    }
    return cnt;
  }
};