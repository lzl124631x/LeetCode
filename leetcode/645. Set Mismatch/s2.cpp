// OJ: https://leetcode.com/problems/set-mismatch/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup, missing = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) dup = nums[i];
            else if (nums[i] > nums[i - 1] + 1) missing = nums[i - 1] + 1;
        }
        return { dup, nums.back() != nums.size() ? nums.size() : missing };
    }
};