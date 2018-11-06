// OJ: https://leetcode.com/problems/search-for-a-range
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int L = 0, R = nums.size() - 1;
    while (L <= R) {
      int M = (L + R) / 2;
      if (nums[M] < target) ++L;
      else --R;
    }
    if (L >= nums.size() || nums[L] != target) return {-1, -1};
    int left = L;
    L = 0, R = nums.size() - 1;
    while (L <= R) {
      int M = (L + R) / 2;
      if (nums[M] <= target) ++L;
      else --R;
    }
    return { left, R };
  }
};