// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
private:
  set<vector<int>> s;
  void dfs(vector<int> &nums, int start, vector<int> &seq) {
    if (seq.size() > 1) s.insert(seq);
    for (int i = start; i < nums.size(); ++i) {
      if (seq.size() && nums[i] < seq.back()) continue;
      seq.push_back(nums[i]);
      dfs(nums, i + 1, seq);
      seq.pop_back();
    }
  }
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> seq;
    dfs(nums, 0, seq);
    return vector<vector<int>>(s.begin(), s.end());
  }
};