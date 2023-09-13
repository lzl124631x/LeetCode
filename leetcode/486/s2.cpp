// OJ: https://leetcode.com/problems/predict-the-winner/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) dp[i] = nums[i];
        for (int len = 2; len <= N; ++len)
            for (int i = 0; i <= N - len; ++i)
                dp[i] = max(nums[i] - dp[i + 1], nums[i + len - 1] - dp[i]);
        return dp[0] >= 0;
    }
};