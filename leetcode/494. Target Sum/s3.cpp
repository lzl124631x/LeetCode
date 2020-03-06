// OJ: https://leetcode.com/problems/target-sum/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
typedef long long LL;
class Solution {
    vector<unordered_map<int, int>> memo;
    int dfs(vector<int> &nums, int start, LL target) {
        if (start == nums.size()) return target == 0;
        if (memo[start].count(target)) return memo[start][target];
        return memo[start][target] = dfs(nums, start + 1, target - nums[start])
            + dfs(nums, start + 1, target + nums[start]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        memo = vector<unordered_map<int, int>>(nums.size());
        return dfs(nums, 0, S);
    }
};