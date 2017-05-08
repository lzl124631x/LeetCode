// OJ: https://leetcode.com/problems/k-diff-pairs-in-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;
    for (int n : nums) m[n]++;
    int cnt = 0;
    for (auto p : m) {
      if ((!k && p.second > 1)
        || (k && m.count(p.first + k))) ++cnt;
    }
    return cnt;
  }
};