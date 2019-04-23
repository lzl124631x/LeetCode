// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
private:
    void heapify(vector<int> &nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; --i)
            siftDown(nums, i, nums.size());
    }
    void siftDown(vector<int> &nums, int hole, int end) {
        int next = 2 * hole + 1;
        while (next < end) {
            if (next + 1 < end && nums[next + 1] > nums[next]) ++next;
            if (nums[hole] > nums[next]) break;
            swap(nums[hole], nums[next]);
            hole = next;
            next = 2 * next + 1;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapify(nums);
        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            siftDown(nums, 0, i);
        }
        return nums;
    }
};