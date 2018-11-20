// OJ: https://leetcode.com/problems/subsets
// Author: github.com/lzl124631x
// Time: O(N^2 * 2^N)
// Space: O(N)
class Solution {
private:
  vector<vector<int>> ans;
  void dfs(vector<int> &nums, int start, int len, vector<int> &tmp) {
    if (!len) {
      ans.push_back(tmp);
      return;
    }
    for (int i = start; i <= nums.size() - len; ++i) {
      tmp.push_back(nums[i]);
      dfs(nums, i + 1, len - 1, tmp);
      tmp.pop_back();
    }
  }
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> tmp;
    for (int len = 0; len <= nums.size(); ++len) dfs(nums, 0, len, tmp);
    return ans;
  }
};