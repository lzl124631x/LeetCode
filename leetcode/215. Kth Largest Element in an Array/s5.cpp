// Author: github.com/lzl124631x
// Time: O(k + (N - k)logk)
// Space: O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.begin() + k, greater<int>());
    for (int i = k; i < nums.size(); ++i) {
      if (nums[i] > nums[0]) {
        pop_heap(nums.begin(), nums.end());
        swap(nums[k - 1], nums[i]);
        push_heap(nums.begin(), nums.end());
      }
    }
    return nums[0];
  }
};