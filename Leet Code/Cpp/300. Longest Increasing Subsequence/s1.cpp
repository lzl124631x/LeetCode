class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size(), ans = 0;
        vector<int> dp(N, 1);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};