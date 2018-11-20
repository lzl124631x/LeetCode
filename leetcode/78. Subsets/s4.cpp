// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(1)
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans(1);
    for (int i = 0; i < nums.size(); ++i) {
      int len = ans.size();
      for (int j = 0; j < len; ++j) {
        ans.push_back(ans[j]);
        ans.back().push_back(nums[i]);
      }
    }
    return ans;
  }
};