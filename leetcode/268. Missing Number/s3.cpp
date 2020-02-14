// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), xorVal = 0;
        for (int i = 0; i < n; ++i) xorVal ^= nums[i] ^ (i + 1);
        return xorVal;
    }
};