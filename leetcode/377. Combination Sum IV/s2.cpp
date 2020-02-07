// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int n : nums) {
                if (n > i) break;
                dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};