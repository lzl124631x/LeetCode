// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int ans = 0;
    for (int n : nums) ans ^= n;
    return ans;
  }
};