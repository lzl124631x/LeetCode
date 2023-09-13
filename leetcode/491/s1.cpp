// OJ: https://leetcode.com/problems/increasing-subsequences
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    set<vector<int>> ans;
    ans.insert(vector<int>());
    for (int i = 0; i < nums.size(); ++i) {
      set<vector<int>> newAns = ans;
      for (auto it = ans.begin(); it != ans.end(); ++it) {
        vector<int> seq = *it;
        if (seq.size() && nums[i] < seq.back()) continue;
        seq.push_back(nums[i]);
        newAns.insert(seq);
      }
      ans = newAns;
    }
    for (auto it = ans.begin(); it != ans.end(); ) {
      if (it->size() <= 1) it = ans.erase(it);
      else ++it;
    }
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};