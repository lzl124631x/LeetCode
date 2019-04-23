// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0, N = nums.size(); i < N; ++i) {
            for (int j = N - 1; j > i; --j) {
                if (nums[j] < nums[j - 1]) swap(nums[j], nums[j - 1]);
            }
        }
        return nums;
    }
};