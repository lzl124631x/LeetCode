// OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (j - 2 < 0 || nums[j - 2] != nums[i]) nums[j++] = nums[i];
    return j;
  }
};