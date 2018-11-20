// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/2764/my-solution-using-bit-manipulation
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int N = 1 << nums.size();
    vector<vector<int>> ans(N, vector<int>());
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < N; ++j) {
        if ((j >> i) & 1) ans[j].push_back(nums[i]);
      }
    }
    return ans;
  }
};