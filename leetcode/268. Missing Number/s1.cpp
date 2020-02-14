// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; ++i) sum += nums[i];
        return n * (n + 1) / 2 - sum;
    }
};