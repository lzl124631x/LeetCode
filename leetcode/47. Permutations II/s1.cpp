// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N^2)
class Solution {
private:
  vector<vector<int>> ans;
  void permute(vector<int> &nums, int start) {
    if (start == nums.size()) {
      ans.push_back(nums);
      return;
    }
    set<int> s;
    for (int i = start; i < nums.size(); ++i) {
      if (s.count(nums[i])) continue;
      swap(nums[i], nums[start]);
      permute(nums, start + 1);
      swap(nums[i], nums[start]);
      s.insert(nums[i]);
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    permute(nums, 0);
    return ans;
  }
};