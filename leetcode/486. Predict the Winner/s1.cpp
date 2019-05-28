// OJ: https://leetcode.com/problems/predict-the-winner/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, unordered_map<int, int>> dp;
        for (int i = 0; i < N; ++i) dp[i][1] = nums[i];
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                dp[i][len] = max(nums[i] - dp[i + 1][len - 1], nums[i + len - 1] - dp[i][len - 1]);
            }
        }
        return dp[0][N] >= 0;
    }
};