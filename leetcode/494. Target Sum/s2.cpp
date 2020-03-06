// OJ: https://leetcode.com/problems/target-sum/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
typedef long long LL;
class Solution {
    int dfs(vector<int> &nums, int start, LL target) {
        if (start == nums.size()) return target == 0;
        return dfs(nums, start + 1, target - nums[start])
            + dfs(nums, start + 1, target + nums[start]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, S);
    }
};