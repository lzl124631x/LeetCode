// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int lb = INT_MAX, rb = INT_MIN;
    for (int i = 1; i < nums.size(); ++i) {
      int val = nums[i], j = i;
      for (; j - 1 >= 0 && nums[j - 1] > val; --j) nums[j] = nums[j - 1];
      nums[j] = val;
      if (j != i) {
        lb = min(lb, j);
        rb = i;
      }
    }
    return lb == INT_MAX ? 0 : rb - lb + 1;
  }
};