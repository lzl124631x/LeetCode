// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    sort_heap(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};