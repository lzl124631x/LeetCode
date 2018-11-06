// OJ: https://leetcode.com/problems/partition-equal-subset-sum
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(MAX_NUM, MAX_ARRAY_SIZE)
// Ref: https://discuss.leetcode.com/topic/62334/simple-c-4-line-solution-using-a-bitset
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    const int MAX_NUM = 100;
    const int MAX_ARRAY_SIZE = 200;
    bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (auto n : nums) bits |= bits << n;
    return !(sum & 1) && bits[sum >> 1];
  }
};