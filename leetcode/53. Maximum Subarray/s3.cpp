// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += max(nums[i - 1], 0);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};