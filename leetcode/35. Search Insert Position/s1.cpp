// OJ: https://leetcode.com/problems/search-insert-position
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int L = 0, R = nums.size() - 1;
    while (L <= R) {
      int M = L + (R - L) / 2;
      if (nums[M] < target) L = M + 1;
      else R = M - 1;
    }
    return L;
  }
};