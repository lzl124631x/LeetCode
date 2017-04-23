// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
private:
  vector<unordered_map<int, int>> memo;
  int dfs(vector<int>& nums, int S, int start) {
    if (start == nums.size()) return !S ? 1 : 0;
    if (memo[start].count(S)) return memo[start][S];
    return memo[start][S] = dfs(nums, S + nums[start], start + 1)
                            + dfs(nums, S - nums[start], start + 1);
  }
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    memo = vector<unordered_map<int, int>>(nums.size());
    return dfs(nums, S, 0);
  }
};