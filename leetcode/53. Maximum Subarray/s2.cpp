// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, N = nums.size();
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < N; ++i) ans = max(ans, dp[i + 1] = max(dp[i], 0) + nums[i]);
        return ans;
    }
};