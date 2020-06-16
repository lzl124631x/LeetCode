// OJ: https://leetcode.com/problems/running-sum-of-1d-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        return nums;
    }
};