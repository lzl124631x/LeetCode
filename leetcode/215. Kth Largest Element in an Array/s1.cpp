// Author: github.com/lzl124631x
// Time: O(N + klogN)
// Space: O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    while (--k) {
      pop_heap(nums.begin(), nums.end());
      nums.pop_back();
    }
    return nums[0];
  }
};