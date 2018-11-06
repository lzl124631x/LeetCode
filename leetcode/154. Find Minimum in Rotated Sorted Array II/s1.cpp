// OJ: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii
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
      else if (nums[M] < nums[R]) R = M;
      else --R;
    }
    return nums[L];
  }
};