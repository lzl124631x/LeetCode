// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N + klogN)
// Space: O(1)
class Solution {
private:
  void percolateDown(vector<int>&nums, int end, int index) {
    if (index < 0 || index >= end) return;
    int child = 2 * index + 1;
    while (child < end) {
      if (child + 1 < end && nums[child + 1] > nums[child]) ++child;
      if (nums[index] > nums[child]) break;
      swap(nums[index], nums[child]);
      index = child;
      child = 2 * index + 1;
    }
  }
  void heapify(vector<int>&nums) {
    for (int i = (nums.size() >> 1) - 1; i >= 0; --i) {
      percolateDown(nums, nums.size(), i);
    }
  }
public:
  int findKthLargest(vector<int>& nums, int k) {
    heapify(nums);
    int size = nums.size();
    for (int i = 1; i < k; ++i) {
      swap(nums[0], nums[size - 1]);
      --size;
      percolateDown(nums, size, 0);
    }
    return nums[0];
  }
};