// OJ: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
  int findMin(vector<int>& nums) {
    int L = 0, R = nums.size() - 1;
    while (L < R) {
      int M = (L + R) / 2;
      if (nums[M] > nums[R]) L = M + 1;
      else R = M;
    }
    return nums[L];
  }
};