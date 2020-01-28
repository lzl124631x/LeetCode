// OJ: https://leetcode.com/problems/permutations/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(1)
class Solution {
    bool nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            while (j > i && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        return i >= 0;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans { nums };
        while (nextPermutation(nums)) ans.push_back(nums);
        return ans;
    }
};