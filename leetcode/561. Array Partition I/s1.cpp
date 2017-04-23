// OJ: https://leetcode.com/problems/array-partition-i
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); sum += nums[i], i += 2);
    return sum;
  }
};