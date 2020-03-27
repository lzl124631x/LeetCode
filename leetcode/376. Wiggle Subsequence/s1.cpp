// OJ: https://leetcode.com/problems/wiggle-subsequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int inc = 1, dec = 1, N = nums.size();
        for (int i = 1; i < N; ++i) {
            if (nums[i] > nums[i - 1]) inc = dec + 1;
            else if (nums[i] < nums[i - 1]) dec = inc + 1;
        }
        return max(inc, dec);
    }
};