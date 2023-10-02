// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
// Ref: https://discuss.leetcode.com/topic/80892/concise-c-solution-use-set-instead-of-map
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_set<int> s;
    int sum = 0, prev = 0;
    for (int n : nums) {
      sum += n;
      if (k) sum %= k;
      if (s.count(sum)) return true;
      s.insert(prev);
      prev = sum;
    }
    return false;
  }
};