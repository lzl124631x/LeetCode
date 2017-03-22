// OJ: https://leetcode.com/problems/continuous-subarray-sum
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
// Ref: https://discuss.leetcode.com/topic/80892/concise-c-solution-use-set-instead-of-map
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_set<int> s;
    int sum = 0, pre = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (k) sum %= k;
      if (s.count(sum)) return true;
      s.insert(pre);
      pre = sum;
    }
    return false;
  }
};