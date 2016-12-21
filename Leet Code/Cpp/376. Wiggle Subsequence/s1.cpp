class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = dp[0][1] = 1;
        int maxLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] - nums[j] > 0) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                    maxLen = max(dp[i][0], maxLen);
                } else if (nums[i] - nums[j] < 0) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                    maxLen = max(dp[i][1], maxLen);
                }
            }
        }
        return maxLen;
    }
};

// Space: O(n)
// Time: O(n^2)