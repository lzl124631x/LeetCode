// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
  vector<vector<int>> ans;
  void dfs(vector<int> &nums, int start, vector<int> &seq) {
    if (start == nums.size()) return;
    unordered_set<int> visited;
    for (int i = start; i < nums.size(); ++i) {
      int n = nums[i];
      if (visited.count(n) || (seq.size() && seq.back() > n)) continue;
      visited.insert(n);
      seq.push_back(n);
      if (seq.size() > 1) ans.push_back(seq);
      dfs(nums, i + 1, seq);
      seq.pop_back();
    }
  }
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> seq;
    dfs(nums, 0, seq);
    return ans;
  }
};