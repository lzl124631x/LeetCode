// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
  int cnt = 0;
  void dfs(vector<int>& nums, int S, int start) {
    if (start == nums.size()) {
      cnt += !S;
      return;
    }
    dfs(nums, S + nums[start], start + 1);
    dfs(nums, S - nums[start], start + 1);
  }
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    dfs(nums, S, 0);
    return cnt;
  }
};