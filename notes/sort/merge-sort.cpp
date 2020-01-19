// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
private:
    void _mergeSort(vector<int> &nums, vector<int> &tmp, int start, int end) {
        if (start + 1 >= end) return;
        int mid = (start + end) / 2;
        _mergeSort(nums, tmp, start, mid);
        _mergeSort(nums, tmp, mid, end);
        for (int i = start, j = mid, k = 0; i < mid || j < end; ++k) {
            tmp[k] = (i >= mid || (j < end && nums[j] < nums[i])) ? nums[j++] : nums[i++];
        }
        for (int i = start; i < end; ++i) nums[i] = tmp[i - start];
    }
    void mergeSort(vector<int> &nums, int start, int end) {
        vector<int> tmp(end - start);
        _mergeSort(nums, tmp, start, end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size());
        return nums;
    }
};