// OJ: https://leetcode.com/problems/permutations
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
private:
  vector<vector<int>> ans;
  void permute(vector<int> &nums, int start) {
    if (start == nums.size() - 1) {
      ans.push_back(nums);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      swap(nums[start], nums[i]);
      permute(nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }
public:
  vector<vector<int>> permute(vector<int>& nums) {
    permute(nums, 0);
    return ans;
  }
};