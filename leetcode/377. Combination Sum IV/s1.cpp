// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(T)
class Solution {
    unordered_map<int, int> m {{0, 1}};
    int dp(vector<int>& nums, int target) {
        if (m.count(target)) return m[target];
        int cnt = 0;
        for (int n : nums) {
            if (n > target) break;
            cnt += dp(nums, target - n);
        }
        return m[target] = cnt;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return dp(nums, target);
    }
};