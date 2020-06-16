// OJ: https://leetcode.com/problems/running-sum-of-1d-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        return nums;
    }
};