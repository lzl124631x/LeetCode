// OJ: https://leetcode.com/problems/target-sum
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    unordered_map<int, int> ans;
    ans[0] = 1;
    for (int n : nums) {
      unordered_map<int, int> newAns;
      for (auto p : ans) {
        int sum = p.first, cnt = p.second;
        newAns[sum + n] += cnt;
        newAns[sum - n] += cnt;
      }
      ans = newAns;
    }
    return ans[S];
  }
};